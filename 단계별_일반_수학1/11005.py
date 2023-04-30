# 진법 변환 2
N, B = map(int, input().split())
num = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ans = ''

while N != 0:
    ans += num[N%B]
    N //= B
    
print(ans[::-1])
