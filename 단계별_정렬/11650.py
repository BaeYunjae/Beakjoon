# 좌표 정렬하기
import sys
input = sys.stdin.readline

n = int(input())
points = []

for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))

for i in sorted(points):
    print(*i)
    
