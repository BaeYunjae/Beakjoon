# 수 정렬하기
# 첫 번째 풀이
n = int(input())
A = [0] * n

for i in range(n):
    A[i] = int(input())
    
A.sort()

for i in range(n):
    print(A[i])
   
------------------------

# 두 번째 풀이
n = int(input())
num_list = []

for _ in range(n):
    num_list.append(int(input()))
    
numList = sorted(num_list)

for i in range(n):
    print(numList[i])
