import torch

# 检查CUDA是否可用
if torch.cuda.is_available():
    print("CUDA is available!")
    # 获取CUDA设备数量
    num_devices = torch.cuda.device_count()
    print(f"Number of CUDA devices: {num_devices}")
    # 输出每个CUDA设备的相关信息
    for device_idx in range(num_devices):
        device = torch.device(f"cuda:{device_idx}")
        print(f"Device {device_idx}: {torch.cuda.get_device_name(device)}")
        print(f"Device {device_idx} memory: {torch.cuda.get_device_properties(device).total_memory / (1024 ** 3)} GB")
else:
    print("CUDA is not available.")