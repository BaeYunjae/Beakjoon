# 서로 다른 부분 문자열의 개수
# 첫번째 풀이 (257316KB, 584ms)
S = input()
S_list = []
for i in range(len(S)):
    for j in range(len(S)):
        S_list.append(S[i:j + 1])

print(len(set(S_list))-1)

-----------------------------------
# 두번째 풀이 (240888KB, 532ms)
S = input()
S_list = set()
for i in range(len(S)):
    for j in range(i, len(S)):
        S_list.add(S[i:j + 1])

print(len(S_list))
