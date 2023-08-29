# 수열
import sys
input = sys.stdin.readline

N, K = map(int, input().split())  # 전체 날짜 수, 연속적인 날짜 수
temps = list(map(int, input().split()))
sum_temp = sum(temps[:K])         # 첫 구간합
MAX = sum_temp

# N = 10, K = 5면 (0~4, 1~5, 2~6, 3~7, 4~8, 5~9) 6개 구간합만 구하면 됨
for i in range(N - K):            # i=4면 temps[4+5], 즉 마지막 값이 더해지므로 i=5까지 갈 필요없음
    sum_temp += temps[i + K] - temps[i]
    if MAX < sum_temp:            # MAX = max(MAX, sum_temp) 보다 빠름
        MAX = sum_temp

print(MAX)

--------------------------------------------------------------------------------------------------
# 시간 초과
import sys
input = sys.stdin.readline

N, K = map(int, input().split())  # 전체 날짜 수, 연속적인 날짜 수
temps = list(map(int, input().split()))
sum_temp = [0]

for i in range(N - K + 1):
    cnt = 0
    for j in range(i, i + K):
        cnt += temps[j]
    sum_temp.append(cnt)

# print(sum_temp)
print(max(sum_temp))

