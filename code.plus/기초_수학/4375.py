# 1
# 첫번째 풀이 (1888ms)
while 1:
    try:
        one = "1"
        n = int(input())
        while 1:
            if int(one) % n == 0:
                print(len(one))
                break
            one += "1"
    except: break
      
----------------------------------------------------------------
# 두번째 풀이 (164ms)
while 1:
    try:
        n = int(input())
    except:
        break

    one = 1  # 1로만 이루어진 수
    cnt = 1  # 자리수
    while 1:
        if one % n != 0:        # n의 배수가 아니라면
            one = one * 10 + 1  # 1로만 이루어진 다음 수로 갱신
            cnt += 1            # 자리수 더하기
        else:                   # n의 배수라면
            break               # 종료

    print(cnt)
