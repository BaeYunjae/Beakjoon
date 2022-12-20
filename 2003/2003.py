import sys
sys.stdin = open('input_2003', 'r')

n, m = map(int, input().split())
A = list(map(int, input().split()))

start_index = 0
end_index = 0
count = 0

while end_index != n:
    s = sum(A[start_index:end_index+1])
    if s == m:
        count += 1
        end_index += 1
    elif s < m:
        end_index += 1
    else:
        start_index += 1

print(count)
