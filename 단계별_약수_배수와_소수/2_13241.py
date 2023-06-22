# 최소공배수
# 유클리드 호제법으로 최대공약수를 (그리고 최소공배수도) 빠르게 구하는 문제
def gcd(a, b):
    if b == 0:
        return a              # a가 최대 공약수
    else:
        return gcd(b, a % b)  # gcd(작은 수, 큰 수 % 작은 수)        

A, B = map(int, input().split())
result = A * B / gcd(A, B)
print(int(result))
