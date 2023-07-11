# 요세푸스 문제 0
n, k = map(int, input().split())
people = [i for i in range(1, n + 1)]
result = []

num = 0

for _ in range(n):
    num += k - 1
    if num >= len(people):
        num = num % len(people)
    result.append(people.pop(num))

print("<", ', '.join(str(i) for i in result), ">", sep="")
