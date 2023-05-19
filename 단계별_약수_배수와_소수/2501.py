# 약수 구하기
# 첫 번째 풀이 (31256 KB, 44 ms)
n, k = map(int, input().split())
divisor = []

for i in range(1, n + 1):
    if n % i == 0:
        divisor.append(i)
        
if len(divisor) >= k:
    print(divisor[k-1])
else:
    print(0)

----------------------------------
    
# 두 번째 풀이 (31388 KB, 40 ms)
n, k = map(int, input().split())
result = 0

for i in range(1, n + 1):
    if n % i == 0:
        k -= 1
        if k == 0:
            result = i
            break
            
print(result)
