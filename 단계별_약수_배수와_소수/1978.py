# 소수 찾기
n = int(input())  # 수의 개수
nums = list(map(int, input().split()))
cnt = 0

for i in nums:
    for j in range(2, i + 1):
        if i % j == 0:
            if i == j:
                cnt += 1
            break

print(cnt)
