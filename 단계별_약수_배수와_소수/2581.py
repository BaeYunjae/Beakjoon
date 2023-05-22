# 소수
m = int(input())
n = int(input())
divisor = []

for i in range(m, n + 1):
    for j in range(2, i + 1):
        if i % j == 0:
            if i == j:
                divisor.append(i)
            break
            
if divisor:
    print(sum(divisor))
    print(min(divisor))
else:
    print(-1)
