# 숫자 카드
# 이진 탐색 - 113364KB	3360ms
# 해시      - 115404KB	 804ms
import sys
input = sys.stdin.readline

n = int(input())
have_list = list(map(int, input().split()))
m = int(input())
target_list = list(map(int, input().split()))

hash = {}

for card in have_list:
    if card not in hash:
        hash[card] = 1

for target in target_list:
    if target in hash:
        print(hash[target], end=' ')
    else:
        print(0, end=' ')
