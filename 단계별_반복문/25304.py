# 영수증
total_price = int(input())
total_num = int(input())
real_sum = 0

for i in range(total_num):
    price, num = map(int, input().split())
    real_sum += price * num
    
if real_sum == total_price:
    print("Yes")
else:
    print("No")
