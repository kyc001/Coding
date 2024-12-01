import torch
import torch.nn as nn

# 定义一个简单的全连接神经网络模型
class SimpleNet(nn.Module):
    def __init__(self):
        super(SimpleNet, self).__init__()
        self.fc1 = nn.Linear(10, 5)
        self.fc2 = nn.Linear(5, 1)

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        return torch.sigmoid(self.fc2(x))

# 检查CUDA是否可用，并根据情况将模型转移到CUDA设备上
if torch.cuda.is_available():
    device = torch.device("cuda")
    model = SimpleNet().to(device)
else:
    model = SimpleNet()

# 创建一些随机输入数据，并根据CUDA可用性将其转移到相应设备上
input_data = torch.randn(1, 10)
if torch.cuda.is_available():
    input_data = input_data.to(device)

# 进行模型的前向传播，模拟一次简单的推理过程
output = model(input_data)
print(f"Model output: {output}")