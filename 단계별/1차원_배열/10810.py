# 공 넣기
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
basket = [0] * n

for i in range(m):
    s, e, ball = map(int, input().split())
    for j in range(s-1, e):
        basket[j] = ball
        
for num in basket:
    print(num, end=' ')
