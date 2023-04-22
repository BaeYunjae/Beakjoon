# 단어 공부
# 첫번째 풀이 (256ms)
from collections import Counter

s = [i.upper() for i in input()]
counter = Counter(s)

max_value = list(key for key, value in counter.items() if value == max(counter.values()))
mostUse = max(counter, key=counter.get)

if len(max_value) > 1:
    print("?")
else:
    print(mostUse)
    
------------------------------------------------------------------------------------------

# 두번째 풀이 (80ms)
words = input().upper()
words_list = list(set(words))

cnt_list = []
for s in words_list:
    cnt = words.count(s)
    cnt_list.append(cnt)
    
if cnt_list.count(max(cnt_list)) > 1:
    print("?")
else:
    max_index = cnt_list.index(max(cnt_list))
    print(words_list[max_index])
    
