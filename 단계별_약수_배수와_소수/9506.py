# 약수들의 합
while True:
    n = int(input())
    if n == -1:
        break
         
    divisor = []
    for i in range(1, n//2 + 1):
        if n % i == 0:
            divisor.append(i)
    
    if sum(divisor) == n:
        print(n, "=", end=" ")
        print(*divisor, sep=" + ")
    else:
        print("%d is NOT perfect." %n)
