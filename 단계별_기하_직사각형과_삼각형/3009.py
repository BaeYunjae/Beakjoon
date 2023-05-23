# 네 번째 점
x_points = []
y_points = []

for _ in range(3):
    x, y = map(int, input().split())
    x_points.append(x)
    y_points.append(y)

for i in x_points:
    if x_points.count(i) == 1:
        print(i, end=' ')
for j in y_points:
    if y_points.count(j) == 1:
        print(j)
