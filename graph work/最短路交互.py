import pandas as pd

# 读取文件
excel_file = pd.ExcelFile(r'D:\Coding\graph work\data\北京市地铁站数据.xls')

# 获取指定工作表中的数据
df = excel_file.parse('Sheet1')

from collections import defaultdict
import networkx as nx

# 创建一个空的有向图
G = nx.DiGraph()

# 构建站点到线路的映射关系
station_to_lines = defaultdict(set)
for _, row in df.iterrows():
    station = row['站点名称']
    line = row['线路名称']
    station_to_lines[station].add(line)

# 添加站点和边到图中
for _, row in df.iterrows():
    station = row['站点名称']
    line = row['线路名称']
    G.add_node(station, lines=station_to_lines[station])
    for neighbor in df[df['线路名称'] == line]['站点名称'].unique():
        if neighbor != station:
            G.add_edge(station, neighbor, line=line)

# 计算最短换乘路线的函数
def shortest_transfer_route(G, start, end):
    # 检查起点和终点是否在图中
    if start not in G or end not in G:
        return None

    # 使用Dijkstra算法计算最短路径
    path = nx.dijkstra_path(G, start, end, weight='weight')

    # 计算换乘信息
    transfer_info = []
    current_line = G[path[0]][path[1]]['line']
    transfer_count = 0
    for i in range(1, len(path) - 1):
        next_line = G[path[i]][path[i + 1]]['line']
        if next_line != current_line:
            transfer_info.append((path[i], current_line, next_line))
            current_line = next_line
            transfer_count += 1

    return path, transfer_info, transfer_count

# 示例使用
# 打印所有站点名称
print('所有站点名称：')
for station in df['站点名称'].unique():
    print(station)

start_station = input('请输入起始站点：')
end_station = input('请输入终点站点：')
route, transfer_info, transfer_count = shortest_transfer_route(G, start_station, end_station)

if route is not None:
    print(f"从 {start_station} 到 {end_station} 的最短换乘路线:")
    print(" -> ".join(route))
    print(f"换乘信息:")
    for transfer in transfer_info:
        print(f"在 {transfer[0]} 站从 {transfer[1]} 换乘到 {transfer[2]}")
    print(f"总换乘次数: {transfer_count}")
else:
    print(f"从 {start_station} 到 {end_station} 没有可达路线")