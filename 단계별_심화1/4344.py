# 평균은 넘겠지
# 첫번째 풀이 (52ms)
c = int(input())

for i in range(c):
    n = list(map(int, input().split()))
    total = 0 
    cnt = 0 
    for j in range(1, n[0] + 1):
        total += n[j]
    avg = total / n[0]
    for k in range(1, n[0] + 1):
        if n[k] > avg:
             cnt += 1
    print(format(cnt/n[0] * 100, ".3f") + "%") 

------------------------------------------------    
    
# 두번째 풀이 (48ms)
c = int(input())

for i in range(c):
    n = list(map(int, input().split()))
    avg = sum(n[1:]) / n[0]
    cnt = 0
    for score in n[1:]:
        if score > avg:
            cnt += 1
    print(format(cnt/n[0] * 100, ".3f") + "%")
              
