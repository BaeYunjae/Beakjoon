# 진법 변환
# 첫 번쨰 풀이 (31388KB, 44ms)
N, B = input().split()
print(int(N, int(B)))

--------------------------------------------

# 두 번째 풀이 (31256KB, 44ms)
N, B = input().split()
num = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

N = N[::-1]
ans = 0

for i in range(len(N)):
    ans += num.find(N[i])*int(B)**i
    
print(ans)
