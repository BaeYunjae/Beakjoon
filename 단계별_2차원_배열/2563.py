# 색종이
n = int(input())
white = [[1 for _ in range(101)] for _ in range(101)]

for _ in range(n):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            white[i][j] = 0
            
answer = 0
for black in white:
    answer += black.count(0)
    
print(answer)
