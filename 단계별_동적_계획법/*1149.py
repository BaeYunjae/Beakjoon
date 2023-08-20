# RGB거리
import sys
input = sys.stdin.readline

n = int(input())
dp = [0] * n

for i in range(n):
    dp[i] = list(map(int, input().split()))

for i in range(1, n):  # 다음 입력값이 이전 입력값의 최솟값을 사용하기 때문에 1부터 시작
    # 인접한 집은 색이 달라야 하기 때문에 
    # 자기 자신을 제외한 2가지 색 중 최솟값을 더하면 비용이 최소가 됨
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + dp[i][0]
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + dp[i][1]
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + dp[i][2]

print(min(dp[n-1][0], dp[n-1][1], dp[n-1][2]))
