# 세탁소 사장 동혁
T = int(input())
n = [25, 10, 5, 1]

for _ in range(T):
    C = int(input())
    for i in n:
        print(C // i, end=' ')
        C %= i
    print()
