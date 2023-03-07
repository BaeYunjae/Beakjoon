import sys
sys.stdin = open('input_11438', 'r')

from collections import deque

n = int(input())                    # 노드의 개수
tree = [[0] for _ in range(n + 1)]  # 트리 데이터 저장

# 인접 리스트에 트리 데이터 저장
for _ in range (0, n - 1):
    s, e = map(int, input().split())
    tree[s].append(e)
    tree[e].append(s)

depth = [0] * (n + 1)        # 노드 깊이 리스트
visited = [False] * (n + 1)  # 방문 여부 저장 리스트
temp = 1
kmax = 0                     # 최대 가능 높이

while temp <= n:  # 최대 가능 depth 구하기
    temp <<= 1    # temp = temp * 2^1
    kmax += 1

# parent 선언 -> [kmax + 1][n + 1]
parent = [[0 for j in range(n + 1)] for i in range(kmax + 1)]

# BFS 함수 구현
def BFS(node):
    queue = deque()
    queue.append(node)
    visited[node] = True
    level = 1             # 트리 깊이
    now_size = 1          # 현재 깊이에서 트리 크기
    count = 0             # 카운트
    while queue:
        now_node = queue.popleft()
        for next in tree[now_node]:
            if not visited[next]:
                visited[next] = True
                queue.append(next)
                parent[0][next] = now_node  # parent[0] 리스트에 자신의 부모 노드 저장
                depth[next] = level         # depth 리스트에 현재 깊이 저장
            count += 1
            if count == now_size:           # 현재 깊이의 모든 노드를 방문
                count = 0
                now_size = len(queue)       # 바로 아래 단계 트리 노드 개수 저장
                level += 1                  # 현재 depth 1 증가

BFS(1)  # depth와 부모 노드를 BFS를 이용해 구하기

for k in range(1, kmax + 1):   # 2^k번째 부모 노드 계산 및 저장
    for n in range(1, n + 1):  # 노드 개수만큼 반복
        # 점화식을 이용해 parent 구성
        parent[k][n] = parent[k - 1][parent[k - 1][n]]

# 빠른 LCA 함수 구현
def executeLCA(a, b):
    if depth[a] > depth[b]:        # 더 깊은 depth가 b가 되도록
        temp = a
        a = b
        b = temp

    # parent 리스트를 이용해 2의 제곱수로 이동
    for k in range(kmax, -1, -1):  # 두 노드의 depth 빠르게 동일하게 맞추기
        if pow(2, k) <= depth[b] - depth[a]:
            if depth[a] <= depth[parent[k][b]]:
                b = parent[k][b]

    for k in range(kmax, -1, -1):  # 두 노드의 같은 조상이 나올 때까지 각 노드를 부모 노드로 변경
        if a == b: break
        if parent[k][a] != parent[k][b]:
            a = parent[k][a]
            b = parent[k][b]

    # 최소 공통 조상 리턴
    LCA = a
    if a != b:
        LCA = parent[0][LCA]
    return LCA

m = int(input())  # 질의 개수

for _ in range(m):
    a, b = map(int, input().split())  # 1번 노드, 2번 노드
    print(str(executeLCA(a, b)))
