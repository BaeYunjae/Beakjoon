# 약수의 합
import sys

MAX = 1000000

dp = [0] * (MAX + 1)
s = [0] * (MAX + 1)

for i in range(1, MAX + 1):  # 1부터 최대값까지
    j = 1                    # i에 곱할 j 선언
    while i * j <= MAX:      # i * j 값이 최대값을 넘지 않을 때까지
        # dp 배열의 인덱스인 i의 배수에 i 더해준다
        # 예를 들어 3 * j에 해당하는 값들은 3를 무조건 약수로 가지기 때문에 3를 더해준다
        dp[i * j] += i
        j += 1
    s[i] = s[i - 1] + dp[i]  # 해당 dp[i]의 값까지 더한 누적합을 s 배열에 넣어준다

T = int(input())

for _ in range(T):
    n = int(sys.stdin.readline())
    sys.stdout.write(str(s[n]) + "\n")  # print(s[n])보다 메모리 크기 작고 시간 빠름
