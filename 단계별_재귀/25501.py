# 재귀의 귀재
# 첫번째 풀이
def recursion(s, l, r):
    if l >= r: return 1          # 문자열이 펠린드롬이다
    elif s[l] != s[r]: return 0  # 문자열이 펠린드롬이 아니다
    else:
        recursion.counter += 1
        return recursion(s, l + 1, r - 1)

def isPalindrome(s):
    recursion.counter += 1
    return recursion(s, 0, len(s)-1)

T = int(input())

for _ in range(T):
    word = input()
    recursion.counter = 0
    print(isPalindrome(word), recursion.counter)

-------------------------------------------------------------
# 두번째 풀이
def recursion(s, l, r):
    global cnt
    cnt += 1
    if l >= r: return 1          # 문자열이 펠린드롬이다
    elif s[l] != s[r]: return 0  # 문자열이 펠린드롬이 아니다
    else: return recursion(s, l + 1, r - 1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1)

T = int(input())

for _ in range(T):
    cnt = 0
    print(isPalindrome(input()), cnt)
