1.运行python fine-tuning.py微调模型，原始模型为Qwen3-1.7B，在/LLM/model/中。微调后的模型将存入./qwen_lora_sft中
2.运行python merge.py合并模型，合并后的模型将存入./qwen_merged_model中
3.运行python fast_api.py开启6006端口，远程服务器可通过ssh隧道访问。

ssh隧道访问如下：
（1）Linux系统在终端运行：
ssh -CNg -L 6006:127.0.0.1:6006 root@connect.cqa1.seetacloud.com -p 12344
（2）输入ssh密码：
7vO48dzdTQ9f   （也许会变）
（3）打开浏览器，访问127.0.0.1:6006/docs，如果页面正常显示则成功连接
