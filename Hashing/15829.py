import sys
sys.stdin = open('input_15829', 'r')

L = int(input())
s = input()
ans = 0

for i in range(L):
    # a: 97, z: 122
    # a ~ z => 1 ~ 26
    ans += (ord(s[i]) - 96) * (31 ** i)

# 해시 함수의 정의에서 유한한 범위의 출력을 가져야 한다.
# 적당히 큰 수 M, 1234567891로 나눠준다.
print(ans % 1234567891)
