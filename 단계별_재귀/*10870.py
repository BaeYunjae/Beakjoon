# 피보나치 수 5
def fibo(n):
    if n < 2:
        return n
    return fibo(n - 1) + fibo(n - 2)

print(fibo(int(input())))
