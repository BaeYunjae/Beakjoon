# 분해합
n = int(input())

for i in range(1, n + 1):
    num = sum(map(int, str(i)))  # i의 각 자리수 합
    nums = i + num               # 분해합 = 생성자 + 각 자리수 합
    if nums == n:
        print(i)
        break
    if i == n:
        print(0)
