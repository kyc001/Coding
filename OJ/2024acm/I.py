n = int(input())
freq = list(map(int, input().split()))

# 将节点和其查询频率组成元组，并按照频率降序排序
nodes = sorted([(i + 1, freq[i]) for i in range(n)], key=lambda x: x[1], reverse=True)

# 简单地构建二叉排序树（这里没有实现平衡操作）
tree = []
for node, _ in nodes:
    if not tree:
        tree.append(node)
    else:
        cur = 0
        while True:
            if node < tree[cur]:
                if 2 * cur + 1 < len(tree):
                    cur = 2 * cur + 1
                else:
                    tree.append(node)
                    break
            else:
                if 2 * cur + 2 < len(tree):
                    cur = 2 * cur + 2
                else:
                    tree.append(node)
                    break

# 计算每个节点的深度
depth = {}
def calculate_depth(node, d=1):
    depth[node] = d
    left = 2 * (node - 1) + 1
    right = 2 * (node - 1) + 2
    if left < len(tree) and tree[left] in depth:
        calculate_depth(tree[left], d + 1)
    if right < len(tree) and tree[right] in depth:
        calculate_depth(tree[right], d + 1)

calculate_depth(tree[0])

# 计算代价
cost = 0
for i in range(n):
    cost += freq[i] * depth[nodes[i][0]]
print(cost)