# 소트인사이드
# 첫 번째 풀이
n = int(input())
print(''.join(sorted(str(n), reverse=True)))

---------------------------------------------

# 두 번째 풀이
n = list(input())
n.sort(reverse=True)

for i in range(len(n)):
    print(n[i], end='')
