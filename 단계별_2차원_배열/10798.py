# 세로읽기
input_list = [list(input()) for _ in range(5)]
max_len = len(max(input_list, key=len))

for j in range(max_len):
    for i in range(5):
        try:
            print(input_list[i][j], end='')
        except:
            continue
