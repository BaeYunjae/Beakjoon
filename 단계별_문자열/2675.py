# 문자열 반복
t = int(input())
answer = []

for i in range(t):
    r, s = input().split()
    sList = list(s)
    for j in range(len(s)):
        sList[j] *= int(r)
    answer.append(''.join(sList))
            
for ans in answer:
    print(ans, end='\n')
        
