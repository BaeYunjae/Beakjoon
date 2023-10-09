# 단지번호붙이기
def dfs(x, y):
    global cnt
    if x <= -1 or x >= n or y <= -1 or y >= n:
        return False
    if map[x][y] == 1:
        map[x][y] = 0
        cnt += 1
        dfs(x - 1, y)
        dfs(x + 1, y)
        dfs(x, y - 1)
        dfs(x, y + 1)
        return True, cnt
    return False

n = int(input())  # 격자 크기
map = [list(map(int, input())) for _ in range(n)]

# 집의 수
homes = 0
# 단지 수
cnts = []

for i in range(n):
    for j in range(n):
        cnt = 0
        if dfs(i, j):
            homes += 1
            cnts.append(cnt)

cnts.sort()
print(homes)
for c in cnts:
    print(c)
