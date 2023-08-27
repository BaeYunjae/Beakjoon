# LCS
import sys
input = sys.stdin.readline

A = ' ' + input().strip()
B = ' ' + input().strip()
dp = [[0] * len(B) for _ in range(len(A))]

for i in range(1, len(A)):
    for j in range(1, len(B)):
        if A[i] == B[j]:                            # 추가된 문자가 같을 때
            dp[i][j] = dp[i-1][j-1] + 1             # 문자가 추가되기 전 최장 길이 + 1
        else:                                       # 추가된 문자가 다를 때
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])  # 기존 문자열 중 최장 길이
            # 이전 최장 길이를 그냥 가져오면 길이 손해
            # (예) ACB, ABA에서 마지막 문자 다르다고 이전 값 가져오면 답은 AB가 아닌 A가 됨

print(dp[-1][-1])
