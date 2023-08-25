# 가장 긴 바이토닉 부분 수열
# 첫번째 풀이
import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
up = [1] * n
down = [1] * n

for i in range(1, n):
    for j in range(i):
        if A[i] > A[j]:
            up[i] = max(up[i], up[j] + 1)

for i in range(n-1, -1, -1):
    for j in range(i, n):
        if A[i] > A[j]:
            down[i] = max(down[i], down[j] + 1)

sum = 0
for i in range(n):
    sum = max(sum, up[i] + down[i])

print(sum - 1)  # up의 가장 큰 수와 down의 가장 큰 수 2번 계산되므로 -1

-----------------------------------------------------------------------
# 두번째 풀이
import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
reverse_A = A[::-1]
up = [1] * n
down = [1] * n


for i in range(1, n):
    for j in range(i):
        if A[i] > A[j]:
            up[i] = max(up[i], up[j] + 1)
        if reverse_A[i] > reverse_A[j]:
            down[i] = max(down[i], down[j] + 1)

sum = 0
for i in range(n):
    sum = max(sum, up[i] + down[n-i-1])  

print(sum - 1)  # up의 가장 큰 수와 down의 가장 큰 수 2번 계산되므로 -1
