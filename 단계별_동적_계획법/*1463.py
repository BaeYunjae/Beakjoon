# 1로 만들기
import sys
input = sys.stdin.readline

n = int(input())
dp = [0] * (n + 1)  # i에서 1로 만드는 최소 연산 횟수
dp[1] = 0           # 1은 연산 불팔요

for i in range(2, n + 1):
    dp[i] = dp[i - 1] + 1                 # (i-1)이 1이 되는 데 필요한 최소한의 연산 + i에서 1을 뻬서 (i-1)이 되는 데 필요한 연산 횟수 1회
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i//2] + 1)  # i를 2로 나눈 값이 1이 되는 데 걸리는 최소 연산 횟수 + i를 2로 나누는 연산 횟수 1회
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i//3] + 1)  # i를 3으로 나눈 값이 1이 되는 데 걸리는 최소 연산 횟수 + i를 3으로 나누는 연산 횟수 1회

print(dp[n])
