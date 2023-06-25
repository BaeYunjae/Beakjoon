# 다음 소수
def isPrime(x):
    if x == 0 or x == 1:
        return False
    else:
        for i in range(2, int(x**0.5) + 1):
            if x % i == 0:
                return False
        return True

n = int(input())

for _ in range(n):
    num = int(input())
    while True:
        if isPrime(num):
            print(num)
            break
        else:
            num += 1
