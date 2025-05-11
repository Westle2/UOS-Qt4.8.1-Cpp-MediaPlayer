from transformers import AutoTokenizer, AutoModelForCausalLM, TrainingArguments, Trainer, DataCollatorForLanguageModeling
from peft import LoraConfig, get_peft_model, prepare_model_for_kbit_training
from datasets import load_dataset
import torch

# ===== 1. 路径配置 =====
model_path = "/root/autodl-tmp/model/"  # 你的Qwen模型路径
dataset_path = "/root/autodl-tmp/music_recommendation_dataset.jsonl"  # 你的数据集路径 (jsonl 格式)

# ===== 2. 加载模型 & tokenizer =====
tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
model = AutoModelForCausalLM.from_pretrained(
    model_path,
    trust_remote_code=True,
    device_map='auto',
    load_in_4bit=True
)

# ===== 3. LoRA配置 =====
config = LoraConfig(
    r=8,
    lora_alpha=32,
    target_modules=["q_proj", "v_proj"],
    lora_dropout=0.05,
    bias="none",
    task_type="CAUSAL_LM"
)

model = prepare_model_for_kbit_training(model)
model = get_peft_model(model, config)

# ===== 4. 加载数据集 =====
dataset = load_dataset('json', data_files=dataset_path, split='train')

# ===== 5. Tokenize: 拼接 input + target =====
def format_and_tokenize(example):
    # 模仿ChatGPT式Prompt结构
    input_text = example['input'].strip()
    target_text = example['target'].strip()

    full_prompt = f"[用户提问]\n{input_text}\n\n[智能推荐]\n{target_text}"

    result = tokenizer(
        full_prompt,
        truncation=True,
        max_length=512,
        padding='max_length'
    )
    return result

tokenized_dataset = dataset.map(format_and_tokenize, batched=False)

# ===== 6. 数据整理器 (自动mask) =====
data_collator = DataCollatorForLanguageModeling(
    tokenizer=tokenizer,
    mlm=False
)

# ===== 7. 训练参数 =====
training_args = TrainingArguments(
    output_dir="./qwen_lora_sft",
    per_device_train_batch_size=4,
    gradient_accumulation_steps=4,
    num_train_epochs=3,
    learning_rate=2e-4,
    fp16=True,
    logging_steps=10,
    save_strategy="epoch",
    save_total_limit=2,
)

# ===== 8. Trainer =====
trainer = Trainer(
    model=model,
    args=training_args,
    train_dataset=tokenized_dataset,
    data_collator=data_collator,
)

# ===== 9. 开始训练 =====
trainer.train()

# ===== 10. 保存LoRA微调模型 =====
model.save_pretrained("./qwen_lora_sft")
tokenizer.save_pretrained("./qwen_lora_sft")

print("指令微调完成，模型保存在 ./qwen_lora_sft")