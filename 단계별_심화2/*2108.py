# 통계학 
import sys
input = sys.stdin.readline

from collections import Counter

n = int(input())
num_list = [int(input()) for _ in range(n)]
num_list.sort()

num_cnt = Counter(num_list).most_common()

print(round(sum(num_list)/n))
print(num_list[n//2])

if len(num_cnt) > 1 and num_cnt[0][1] == num_cnt[1][1]:
    print(num_cnt[1][0])
else:
    print(num_cnt[0][0])

print(num_list[-1] - num_list[0])
