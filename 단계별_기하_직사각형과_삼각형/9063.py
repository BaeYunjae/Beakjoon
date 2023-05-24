# 대지
# 첫 번째 풀이 (35588KB, 2068ms)
n = int(input())
x_points = []
y_points = []

for _ in range(n):
    x, y = map(int, input().split())
    x_points.append(x)
    y_points.append(y)
    
x_points = sorted(x_points)
y_points = sorted(y_points)

lenX = x_points[-1] - x_points[0]
lenY = y_points[-1] - y_points[0]
print(lenX*lenY)

------------------------------------

# 두 번째 풀이 (35196KB, 2084ms)
n = int(input())
x_points = []
y_points = []

for _ in range(n):
    x, y = map(int, input().split())
    x_points.append(x)
    y_points.append(y)
    
lenX = max(x_points) - min(x_points)
lenY = max(y_points) - min(y_points)
print(lenX*lenY)
