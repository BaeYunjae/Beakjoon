# 정수 삼각형
import sys
input = sys.stdin.readline

n = int(input())
dp = [0] * n

for i in range(n):
    dp[i] = list(map(int, input().split()))

for i in range(1, n):           
    for j in range(i + 1):     
        if j == 0:              
            dp[i][j] += dp[i-1][j]
        elif i == j:            
            dp[i][j] += dp[i-1][j-1]
        else:                   
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j])

print(max(dp[-1]))
