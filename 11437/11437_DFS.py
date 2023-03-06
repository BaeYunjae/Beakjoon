import sys
sys.stdin = open('input_11437', 'r')

n = int(input())
tree = [[] for _ in range(n + 1)]

for _ in range(0, n - 1):
    s, e = map(int, input().split())
    tree[s].append(e)
    tree[e].append(s)

depth = [0] * (n + 1)
parent = [0] * (n + 1)
visited = [False] * (n + 1)

def DFS(node, d):
    visited[node] = True
    depth[node] = d
    for i in tree[node]:
        if not visited[i]:
            parent[i] = node  # 부모 노드 초기화
            DFS(i, d + 1)

DFS(1, 0)

def LCA(a, b):
    if depth[a] < depth[b]:
        temp = a
        a = b
        b = temp

    while depth[a] != depth[b]:
        a = parent[a]

    while a != b:
        a = parent[a]
        b = parent[b]

    return a

m = int(input())

for _ in range(m):
    a, b = map(int, input().split())
    print(LCA(a, b))