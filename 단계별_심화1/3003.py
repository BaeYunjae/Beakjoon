# 킹, 퀸, 룩, 비숍, 나이트, 폰
piece = [1, 1, 2, 2, 2, 8]
find = list(map(int, input().split()))

print(*[x - y for x, y in zip(piece, find)])
