# 공 바꾸기
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
basket = [i for i in range(1, n + 1)]

for i in range(m):
    a, b = map(int, input().split())
    basket[a-1], basket[b-1] = basket[b-1], basket[a-1]
    
for num in basket:
    print(num, end=' ')
