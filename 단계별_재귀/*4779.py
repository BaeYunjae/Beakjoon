# 칸토어 집합
def cantor(s, lines):  # s: 시작점
    if lines == 1: return
    for i in range(s + lines // 3, s + (lines // 3) * 2):  # 가운데 공백
        result[i] = ' '
    cantor(s, lines // 3)                     # 왼쪽 자르기
    cantor(s + (lines // 3) * 2, lines // 3)  # 오른쪽 자르기

while 1:
    try:
        N = int(input())
        result = ['-'] * (3 ** N)
        cantor(0, 3 ** N)
        print(''.join(result))
    except: break
