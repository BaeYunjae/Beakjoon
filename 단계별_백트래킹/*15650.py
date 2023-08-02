# N과 M (2)
n, m = map(int, input().split())
s = []

def dfs(start):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return

    for i in range(start, n + 1):  # 중복 제거
        if i not in s:
            s.append(i)
            dfs(i + 1)
            s.pop()

dfs(1)
