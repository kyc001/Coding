def mex(arr):
    found = [False] * (len(arr) + 1)
    for a in arr:
        if a <= len(arr):
            found[a] = True
    for i in range(len(arr) + 1):
        if not found[i]:
            return i


n, x = map(int, input().split())
a = list(map(int, input().split()))

# 计算前缀MEX
prefix_mex = [0]
current_set = set()
for i in range(n):
    current_set.add(a[i])
    while True:
        candidate_mex = len(prefix_mex)
        if candidate_mex not in current_set:
            prefix_mex.append(candidate_mex)
        else:
            break

# 二分查找计算出色子数组数量
import bisect
count = 0
for r in range(n):
    # 修正这里，确保二分查找的范围不会越界
    valid_hi = min(len(prefix_mex), r + 1)
    l = bisect.bisect_left(prefix_mex, x, lo=0, hi=valid_hi)
    count += r - l + 1

print(count)