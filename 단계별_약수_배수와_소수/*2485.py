# 가로수
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

n = int(input())    # 심어져 있는 가로수 수
now = int(input())  # 첫 가로수
distances = []      # 가로수 사이 거리

for _ in range(n - 1):
    next = int(input())
    distances.append(next - now)
    now = next

g = distances[0]
for j in range(1, len(distances)):
    g = gcd(g, distances[j])

result = 0
for each in distances:
    result += each // g - 1

print(result)
