# 계단 오르기
import sys
input = sys.stdin.readline

n = int(input())
stairs = [0] * 301  # [0] * n 은 indexerror
for i in range(n):
    stairs[i] = int(input())

dp = [0] * 301
dp[0] = stairs[0]
dp[1] = stairs[0] + stairs[1]
# dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]) => max(45, 35)
# dp[3] = stairs[0] + stairs[1] + stairs[3] = dp[1] + stairs[3]
#     또는 stairs[0] + stairs[2] + stairs[3] = dp[0] + stairs[2] + stairs[3]

for i in range(2, n):
    dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i], dp[i-2] + stairs[i])

print(dp[n-1])
