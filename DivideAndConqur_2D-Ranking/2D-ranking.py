import numpy as np

def sortByX(ele):
    return ele[0]
def sortByY(ele):
    return ele[1]
def sortByRank(ele):
    return ele[2]

def dfs(part):
    # 剩下一個不理他
    if len(part) == 1:
        return part
    # 遞迴
    left = dfs(part[0:len(part)//2])
    right = dfs(part[len(part)//2:len(part)])
    part = []
    # Merge
    for l in left:
        part.append(l)
    for r in right:
        part.append(r)
    # 排Y軸
    part.sort(key=sortByY)
    #將ranking值相加
    biggerThanLeftAmount = 0
    for idx, p in enumerate(part):
        if p in left: biggerThanLeftAmount+=1
        if p in right:
            p[2] += biggerThanLeftAmount
    return part
def ranking(data):
    # print(data)
    left = dfs(data[0:len(data)//2])
    right = dfs(data[len(data)//2:len(data)])
    data = []
    for l in left:
        data.append(l)
    for r in right:
        data.append(r)
    data.sort(key=sortByY)
    biggerThanLeftAmount = 0
    for idx, p in enumerate(data):
        if p in left: biggerThanLeftAmount+=1
        if p in right:
            p[2] += biggerThanLeftAmount
    # print(data)
    return data

n = int(input("輸入測試筆數(-1為隨機10筆(0~100)"))
data = None
result = None
if n == -1:
    data = np.random.randint(0,100,(10,2)).tolist()
else:
    data = []
# print(len(data))
if n == -1:
    for idx in range(len(data)):
        data[idx].append(0)
else:
    for idx in range(n):
        data.append([int(ele) for ele in input().split(" ")])
        data[idx].append(0)
# 預排序
data.sort(key=sortByX)
result = ranking(data)
# print(len(result))
result.sort(key = sortByRank, reverse=True)
# print(result)
for ele in result:
    print(ele[2],":", ele[0], ele[1],)
