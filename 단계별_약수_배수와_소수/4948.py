# 베르트랑 공준
# 첫번째 풀이 (44792KB,	3492ms)
import math

while True:
    n = int(input())
    numList = [0] * (2 * n + 1)
    cnt = 0

    if n == 0:
        break

    for i in range(2, 2 * n + 1):
        numList[i] = i

    for i in range(2, int(math.sqrt(2 * n)) + 1):  # 제곱근까지만 수행
        if numList[i] == 0:
            continue
        for j in range(2 * i, 2 * n + 1, i):       # 배수 지우기
            numList[j] = 0

    for i in range(n + 1, 2 * n + 1):
        if numList[i] != 0:
            cnt += 1

    print(cnt)

--------------------------------------------------------------------
# 두번째 풀이 (40352KB, 596ms)
num = 123456
numList = [0] * (2 * num + 1)

for i in range(2, 2 * num + 1):
    numList[i] = i

for i in range(2, int((2 * num)**0.5) + 1):  # 제곱근까지만 수행
    if numList[i] == 0:
        continue
    for j in range(2 * i, 2 * num + 1, i):   # 배수 지우기
        numList[j] = 0

while True:
    n = int(input())
    cnt = 0

    if n == 0:
        break

    for i in range(n + 1, 2 * n + 1):
        if numList[i] != 0:
            cnt += 1

    print(cnt)
  
