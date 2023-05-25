# 삼각형과 세 변
while True:
    lines = list(map(int, input().split()))
    if 0 in lines: break
    if max(lines) < sum(lines) - max(lines):
        nums = len(set(lines))
        if nums == 1:
            print("Equilateral")
        elif nums == 2:
            print("Isosceles")
        else:
            print("Scalene")
    else:
        print("Invalid")
