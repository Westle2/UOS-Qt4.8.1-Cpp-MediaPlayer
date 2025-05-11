from fastapi import FastAPI
from transformers import AutoTokenizer, AutoModelForCausalLM
import torch
from pydantic import BaseModel

# 设置 FastAPI 应用
app = FastAPI()

# 加载模型和 tokenizer
model_path = "/root/autodl-tmp/qwen_merged_model/"
tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
model = AutoModelForCausalLM.from_pretrained(model_path, trust_remote_code=True, device_map="auto", load_in_4bit=False)

# 定义请求体模型
class TextInput(BaseModel):
    text: str

# 定义文本生成接口
@app.post("/generate")
# async def generate_text(input_data: TextInput):
#     input_text = input_data.text
#     inputs = tokenizer(input_text, return_tensors="pt").to(model.device)
    
#     # 生成文本
#     with torch.no_grad():
#         outputs = model.generate(inputs["input_ids"], max_length=200, num_return_sequences=1, top_p=0.95, top_k=60)

#     generated_text = tokenizer.decode(outputs[0], skip_special_tokens=True)
#     return {"generated_text": generated_text}
async def generate_text(input_data: TextInput):
    user_input = input_data.text
    
    # 让模型知道对话格式和自称“小绪”
    prompt = f"你正在和一个叫小绪的AI聊天。\n\n用户: {user_input}\n小绪: "    
    inputs = tokenizer(prompt, return_tensors="pt").to(model.device)   
    with torch.no_grad():
        outputs = model.generate(inputs["input_ids"], max_length=200, num_return_sequences=1, top_p=0.95, top_k=60)
    generated_text = tokenizer.decode(outputs[0], skip_special_tokens=True)  
    # 只取“小绪:”后面的内容
    reply = generated_text.split("小绪:")[-1].strip()   
    return {"generated_text": reply}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=6006)
