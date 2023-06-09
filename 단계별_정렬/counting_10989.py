# 수 정렬하기 3
# 수의 범위가 작다면 카운팅 정렬을 사용하여 더욱 빠르게 정렬할 수 있습니다.
import sys
input = sys.stdin.readline

n = int(input())
count = [0] * 10001

for i in range(n):
    count[int(input())] += 1
    
for i in range(10001):
    if count[i] != 0:
        for _ in range(count[i]):
            print(i)
