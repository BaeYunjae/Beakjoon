# 소인수분해
# 첫 번째 풀이(31388KB, 1356ms)
n = int(input())
i = 2

while n != 1:
    if n % i == 0:
        print(i)
        n //= i
    else:
        i += 1
       
---------------------------

# 두 번째 풀이(31256KB, 1072ms)
n = int(input())

if n == 1:
    print('')

for i in range(2, n + 1):
    if n % i == 0:
        while n % i == 0:
            print(i)
            n //= i
            
