# 달팽이는 올라가고 싶다
a, b, v = map(int, input().split())
day = (v - b) / (a - b)
print(int(day)) if day == int(day) else print(int(day) + 1)
