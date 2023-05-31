# 수학은 비대면강의입니다
# 첫 번째 풀이
a, b, c, d, e, f = map(int, input().split())

for i in range(-999, 1000):
    for j in range(-999, 1000):
        if a * i + b * j == c and d * i + e * j == f:
            print(i, j)
            break

-------------------------------------------------------            
            
# 두 번째 풀이            
a, b, c, d, e, f = map(int, input().split())
value = []

for i in range(-999, 1000):
    for j in range(-999, 1000):
        if a * i + b * j == c:
            value.append([i, j])

for xy in value:
    if d * xy[0] + e * xy[1] == f:
        print(xy[0], xy[1])
        break   
        
