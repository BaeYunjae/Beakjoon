# 골드바흐 파티션
primeList = [False, False] + [True for _ in range(2, 1000001)]
for i in range(2, int(1000001 ** 0.5) + 1):
    if primeList[i]:
        for j in range(i + i, 1000001, i):
            primeList[j] = False

n = int(input())

for _ in range(n):
    cnt = 0
    T = int(input())

    for i in range(2, T // 2 + 1):
        if primeList[i] and primeList[T - i]:
            cnt += 1
    print(cnt)
