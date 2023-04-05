# 주사위 세개
dice = list(map(int, input().split()))
new = []
for i in dice:
    if i not in new:
        new.append(i)
    else:
        d = i
        
if len(new) == 3:
    print(max(new) * 100)
elif len(new) == 2:
    print(1000 + d * 100)
elif len(new) == 1:
    print(10000 + d * 1000)
