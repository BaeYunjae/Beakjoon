# 알고리즘 수업 - 피보나치 수 1
# 첫번째 풀이
# 재귀함수
def fib(n):
    global c1
    if n <= 2:
        return 1
    else:
        c1 += 1
        return fib(n - 1) + fib(n - 2)

# 동적계획법
def fibonacci(n):
    global c2
    f = [0] * (n + 1)
    for i in range(3, n + 1):
        c2 += 1
        f[i] = f[i - 1] + f[i - 2]
    return f[n]

n = int(input())
c1, c2 = 0, 0
fib(n)
fibonacci(n)
print(c1 + 1, c2)

--------------------------------------
# 두번째 풀이
def fibonacci(n):
    for i in range(3, n + 1):
        f[i] = f[i - 1] + f[i - 2]
    return f[n]

n = int(input())
f = [0] * (n + 1)
f[1] = f[2] = 1
c1 = fibonacci(n)
c2 = n - 2
print(c1, c2)
