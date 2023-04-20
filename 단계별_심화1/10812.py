# 바구니 순서 바꾸기
n, m = map(int, input().split())
basket = [i + 1 for i in range(n)]

for _ in range(m):
    begin, end, mid = map(int, input().split())
    basket = basket[:begin-1] + basket[mid-1:end] + basket[begin-1:mid-1] + basket[end:]
    
for b in basket:
    print(b, end=' ')
