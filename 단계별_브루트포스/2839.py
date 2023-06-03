# 설탕 배달
# 첫 번째 풀이 (180ms)
n = int(input())
bag = []

for i in range(0, 1001):
    for j in range(0, 1001):
        if 3 * i + 5 * j == n:
            bag.append(i + j)

if bag:
    print(min(bag))
else:
    print(-1)
    
-------------------------------

# 두 번째 풀이 (40ms)
n = int(input())
bag = 0

while n >= 0:
    if n % 5 == 0:
        bag += n // 5
        print(bag)
        break
    n -= 3
    bag += 1
else:
    print(-1)
