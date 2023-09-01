# 17점
import sys
input = sys.stdin.readline

n = int(input())
dist = list(map(int, input().split()))
city = list(map(int, input().split()))

remain = sum(dist)
price = 0
for i in range(1, n - 1):
    if remain == 0:
        break
    if city[0] == min(city):
        price = city[0] * remain
        break
    if city[i - 1] >= city[i]:
        price += city[i - 1] * dist[i - 1]
        remain -= price
    else:
        price += city[i - 1] * (dist[i - 1] + dist[i])
        remain -= price

print(price)

----------------------------------------------------------
# *100점
import sys
input = sys.stdin.readline

n = int(input())
dist = list(map(int, input().split()))
city = list(map(int, input().split()))

price = 0
MIN = city[0]
for i in range(n - 1):
    if city[i] < MIN:
        MIN = city[i]
    price += MIN * dist[i]

print(price)
