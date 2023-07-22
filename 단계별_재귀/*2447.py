# 골드 5
# 별 찍기 - 10
def draw_star(n):
    if n == 1: return ['*']

    Stars = draw_star(n // 3)
    L = []

    for star in Stars:
        L.append(star*3)
    for star in Stars:
        L.append(star +' '*(n // 3) + star)
    for star in Stars:
        L.append(star * 3)

    return L

N = int(input())

print('\n'.join(draw_star(N)))

# draw_star(27) -> draw_star(9) -> draw_star(3) -> draw_star(1) -> n == 3의 Stars = ['*'] -> L = ['***', '* *', '***']
# -> n == 9의 Stars = ['***', '* *', '***'] -> n == 9 첫번째 for문 L 에 ['*********', '* ** ** *', '*********'] 추가 
# -> 두번째 for문 L 에 ['***   ***', '* *   * *   * *', '***   ***'] -> ...
