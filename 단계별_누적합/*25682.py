# 체스판 다시 칠하기 2
import sys
input = sys.stdin.readline

def minimal_board(color):
    prefix_sum = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n):
        for j in range(m):
            if (i + j) % 2 == 0:  # 행열 번호 합이 짝수면 시작점 색갈과 같아야 함
                value = board[i][j] != color
            else:
                value = board[i][j] == color
            prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + value

    cnt = sys.maxsize
    for i in range(1, n - k + 2):
        for j in range(1, m - k + 2):
            cnt = min(cnt, prefix_sum[i + k - 1][j + k - 1] - prefix_sum[i + k - 1][j - 1] - prefix_sum[i - 1][j + k - 1] + prefix_sum[i - 1][j - 1])
    return cnt

n, m, k = map(int, input().split())  # m x n -> k x k
board = [input() for _ in range(n)]
print(min(minimal_board('B'), minimal_board('W')))
