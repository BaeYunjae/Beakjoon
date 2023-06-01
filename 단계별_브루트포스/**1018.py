# 체스판 다시 칠하기
n, m = map(int, input().split())
board = []
result = []

for _ in range(n):
    board.append(input())

for i in range(n-7):      # 8x8 크기의 체스판 검사
    for j in range(m-7):
        first_B = 0
        first_W = 0
        for a in range(i, i + 8):
            for b in range(j, j + 8):
                if (a + b) % 2 == 0:         # 시작점과 같은 색깔, W로 시작하면 (0,0) (0,2) (0,4)...가 W
                    if board[a][b] != 'W':
                        first_W += 1
                    if board[a][b] != 'B':
                        first_B += 1
                else:                        # 시작점과 다른 색깔, (0,1) (0,3) (0,5)...는 B
                    if board[a][b] != 'B':
                        first_W += 1
                    if board[a][b] != 'W':
                        first_B += 1
        result.append(min(first_B, first_W))
print(min(result))
