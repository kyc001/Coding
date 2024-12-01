import torch
from torchbenchmark import benchmark

# 定义一个简单的模型示例，比如一个简单的卷积神经网络
class SimpleCNN(torch.nn.Module):
    def __init__(self):
        super(SimpleCNN, self).__init__()
        self.conv1 = torch.nn.Conv2d(3, 6, 5)
        self.pool = torch.nn.MaxPool2d(2, 2)
        self.conv2 = torch.nn.Conv2d(6, 16, 5)
        self.fc1 = torch.nn.Linear(16 * 5 * 5, 120)
        self.fc2 = torch.nn.Linear(120, 84)
        self.fc3 = torch.nn.Linear(84, 10)

    def forward(self, x):
        x = self.pool(torch.nn.functional.relu(self.conv1(x)))
        x = self.pool(torch.nn.functional.relu(self.conv2(x)))
        x = x.view(-1, 16 * 5 * 5)
        x = torch.nn.functional.relu(self.fc1(x))
        x = torch.nn.functional.relu(self.fc2(x))
        return self.fc3(x)

# 创建模型实例并将其转移到CUDA设备（如果可用）
model = SimpleCNN()
if torch.cuda.is_available():
    model = model.cuda()

# 运行基准测试，设置一些参数，比如运行次数、批次大小等（可根据实际调整）
results = benchmark(model, input_size=(1, 3, 32, 32), num_runs=10, batch_size=16)
print(results)