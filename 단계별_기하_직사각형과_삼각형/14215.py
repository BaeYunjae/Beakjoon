# 세 막대
lines = list(map(int, input().split()))
if len(set(lines)) == 1:
    print(sum(lines))
elif max(lines) >= sum(lines) - max(lines):
    lines[lines.index(max(lines))] = sum(lines) - max(lines) - 1
    print(sum(lines))
else:
    print(sum(lines))
