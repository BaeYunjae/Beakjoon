# 나이순 정렬
# 값이 같은 원소의 전후관계가 바뀌지 않는 정렬 알고리즘을 안정 정렬(stable sort)이라고 합니다.
import sys
input = sys.stdin.readline

n = int(input())
judge = []

for i in range(n):
    age, name = input().split()
    judge.append((int(age), name))

judge.sort(key=lambda x: x[0])

for i in judge:
    print(i[0], i[1])
