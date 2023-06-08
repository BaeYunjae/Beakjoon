# 커트라인
n, k = map(int, input().split())
scores = sorted(list(map(int, input().split())))
print(scores[-k])
