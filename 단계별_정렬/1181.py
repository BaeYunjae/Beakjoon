# 단어 정렬
# 첫 번째 풀이 (816ms)
n = int(input())
words = []
for _ in range(n):
    words.append(input())

words_list = list(set(words))
words_list.sort()
words_list.sort(key=len)

for i in words_list:
    print(i)
    
------------------------------

# 두 번째 풀이 (80)
import sys
input = sys.stdin.readline

n = int(input())
words = []
for _ in range(n):
    words.append(input().strip())

words_list = list(set(words))
words_list.sort()
words_list.sort(key=len)

for i in words_list:
    print(i)
