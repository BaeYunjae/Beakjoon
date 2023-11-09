# 행렬 덧셈
n, m = map(int, input().split())
m1 = [list(map(int, input().split())) for _ in range(n)]
m2 = [list(map(int, input().split())) for _ in range(n)]
matrix = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    for j in range(m):
        matrix[i][j] = m1[i][j] + m2[i][j]
        print(matrix[i][j], end = ' ')
    print()
