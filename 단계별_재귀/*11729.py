# 실버 1
# 하노이 탑 이동 순서
def hanoi(num, start, end, other):  
    if num == 0: return
    hanoi(num-1, start, other, end)  
    print(start, end)
    hanoi(num-1, other, end, start)

n = int(input())
print(2**n - 1)
hanoi(n, 1, 3, 2)
