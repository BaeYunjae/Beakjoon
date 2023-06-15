# 숫자 카드 - 이진 탐색
# 첫 번째 풀이 (4264ms)
import sys
input = sys.stdin.readline

n = int(input())
have_list = list(map(int, input().split()))
have_list.sort()
m = int(input())
target_list = list(map(int, input().split()))

for i in range(m):
    find = False
    target = target_list[i]
    # 이진 탐색 시작
    start = 0
    end = n - 1
    while start <= end:
        mid_index = int((start + end) / 2)
        mid_value = have_list[mid_index]
        if mid_value > target:
            end = mid_index - 1
        elif mid_value < target:
            start = mid_index + 1
        else:
            find = True
            break
            
    if find:
        print(1, end=' ')
    else:
        print(0, end=' ')
        
--------------------------------------------

# 두 번째 풀이 (3360ms)
...
...
for target in target_list:
    find = False
    # 이진 탐색 시작
    start, end  = 0, n - 1
    while start <= end:
        mid = (start + end) // 2
        if have[mid] > target:
            end = mid - 1
        elif have[mid] < target:
            start = mid + 1
        else:
            find = True
            break

    print(1 if find else 0, end=' ')
    
