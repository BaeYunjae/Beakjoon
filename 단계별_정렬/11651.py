# 좌표 정렬하기 2
# 첫 번째 풀이 (54084KB, 440ms)
import sys
input = sys.stdin.readline

n = int(input())
points = []

for i in range(n):
    x, y = map(int, input().split())
    points.append([x, y])

points.sort(key=lambda p: (p[1], p[0]))

for i in points:
    print(*i)
    
------------------------------------------------------------------

# 두 번째 풀이 (47548KB,	368ms) - sort() 사용 시 (46764KB, 372ms)
import sys
input = sys.stdin.readline

n = int(input())
points = []

for i in range(n):
    x, y = map(int, input().split())
    points.append([y, x])

p_arr = sorted(points)

for y, x in p_arr:
    print(x, y)
    
