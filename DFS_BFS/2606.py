## DFS
def dfs(computers, v, visited):
    global cnt
    visited[v] = True
    for i in computers[v]:
        if i and not visited[i]:
            cnt += 1
            dfs(computers, i, visited)

n = int(input())  # 컴퓨터 수
m = int(input())  # 컴퓨터 쌍의 수

computers = [[] for _ in range(n + 1)]  
for _ in range(m):
    c1, c2 = map(int, input().split())
    computers[c1].append(c2)  # c1 컴퓨터와 c2 컴퓨터 
    computers[c2].append(c1)  # 서로 연결

# 방문 여부 리스트
visited = [False] * (n + 1)

cnt = 0
dfs(computers, 1, visited)
print(cnt)

-------------------------------------------------------
## BFS
from collections import deque

def bfs(computers, start, visiteed):
    global cnt
    queue = deque()
    queue.append(start)
    visited[start] = True
    while queue:
        v = queue.popleft()
        for i in computers[v]:
            if not visited[i]:
                cnt += 1
                queue.append(i)
                visited[i] = True


n = int(input())  # 컴퓨터 수
m = int(input())  # 컴퓨터 쌍의 수

computers = [[] for _ in range(n + 1)]
for _ in range(m):
    c1, c2 = map(int, input().split())
    computers[c1] += [c2]
    computers[c2] += [c1]

# 방문 여부 리스트
visited = [False] * (n + 1)

cnt = 0
bfs(computers, 1, visited)
print(cnt)
