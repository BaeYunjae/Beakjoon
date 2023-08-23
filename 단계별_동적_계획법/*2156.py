# 포도주 시식
# 2579 계단 오르기와 다른 점 : 마지막 것을 반드시 포함하지 않아도 됨
import sys
input = sys.stdin.readline

n = int(input())
podo = [0] * 10001
for i in range(n):
    podo[i] = int(input())

dp = [0] * 10001
dp[0] = podo[0]
dp[1] = dp[0] + podo[1]


for i in range(2, n):
    # 현재 포도주를 마시지 않았을 경우, 현재 포도주와 이전 포도주 마셨을 경우, 현재 포도주는 마시고 이전 포도주는 마시지 않았을 경우
    dp[i] = max(dp[i-1], podo[i] + podo[i-1] + dp[i-3], podo[i] + dp[i-2])


print(dp[n - 1])
