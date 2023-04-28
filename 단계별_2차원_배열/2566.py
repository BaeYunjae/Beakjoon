# 최댓값
matrix = [list(map(int, input().split())) for _ in range(9)]
max_value = max(map(max, matrix))
Max = [[i+1, j+1] for i in range(9) for j in range(9) if matrix[i][j] == max_value]

print(max_value)
for row, col in Max:
    print(row, col)
