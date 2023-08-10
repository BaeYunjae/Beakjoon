# 약수의 합 2
# 첫번째 풀이 (시간초과)
def divisor(n):
    global ans
    for i in range(1, n + 1):
        if n % i == 0:
            ans += i

def summation(n):
    for i in range(1, n + 1):
        divisor(i)

n = int(input())
ans = 0
summation(n)
print(ans)

-------------------------
# 두번째 풀이
n = int(input())
ans = 0

for i in range(1, n + 1):
    # n의 배수는 항상 n의 약수를 가진다
    # n 이하의 자연수에서 k를 약수로 가지는 수는 n/k개
    # 예) 10 이하의 자연수에서 2를 약수로 가지는 수는 5개 (2, 4, 6, 8, 10)
    # i의 배수 개수 = i를 약수로 갖는 수의 개수
    ans += (n // i) * i
print(ans)
