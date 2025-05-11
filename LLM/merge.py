from peft import PeftModel
from transformers import AutoTokenizer, AutoModelForCausalLM

base_model_path = "/root/autodl-tmp/model/"
lora_model_path = "/root/autodl-tmp/qwen_lora_sft/"
output_dir = "/root/autodl-tmp/qwen_merged_model/"

tokenizer = AutoTokenizer.from_pretrained(base_model_path, trust_remote_code=True)
model = AutoModelForCausalLM.from_pretrained(base_model_path, trust_remote_code=True, device_map='auto', load_in_4bit=False)

# 使用PeftModel.from_pretrained()方法加载LoRA adapter
model = PeftModel.from_pretrained(model, lora_model_path)

# 合并adapter权重到模型
model = model.merge_and_unload()  # 适用于peft老版本

# 保存合并后的模型
model.save_pretrained(output_dir)
tokenizer.save_pretrained(output_dir)
print(f"已保存模型到{output_dir}")
