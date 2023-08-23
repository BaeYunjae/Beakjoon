# 쉬운 계단 수
import sys
input = sys.stdin.readline

n = int(input())
mod = 1000000000

# 수의 길이가 N일 때 숫자 H(1 ~ 9)로 끝나는 계단 수의 모든 경우의 수
D = [[0 for _ in range(11)] for _ in range(n + 1)]

for i in range(1, 10):
    D[1][i] = 1  # 계단이 1개일 때 H로 끝나는 계단 수의 모든 경우의 수는 1
                 # 단, 0으로 시작하는 숫자는 없기 때문에 D[0][1]은 0으로 초기화

for i in range(2, n + 1):
    D[i][0] = D[i-1][1]  # 높이가 -1인 것은 없으므로 N에서 높이가 0이면 N - 1에서는 높이가 1이어야 계단 수 가능
    D[i][9] = D[i-1][8]  # 높이가 10 이상일 수 없으므로 N에서 높이가 9이면 N - 1에서는 높이가 8이어야 계단 수 가능
    for j in range(1, 9):
        # 높이가 1 ~ 8이면 N - 1에서 N보다 한 단계 위 또는 아래 높이에서 올 수 있음
        D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % mod

sum = 0

for i in range(10):
    sum = (sum + D[n][i]) % mod  # 계단의 총 개수

print(sum)
