# 영단어 암기는 괴로워
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dic = dict()

for i in range(n):
    word = input().strip()
    if len(word) >= m:
        if word not in dic:
            dic[word] = 1
        else:
            dic[word] += 1

sorted_dic = sorted(dic.items(), key = lambda x: (-x[1], -len(x[0]), x[0]))

for i in range(len(dic)):
    print(sorted_dic[i][0])
