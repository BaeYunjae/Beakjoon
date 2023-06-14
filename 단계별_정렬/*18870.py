# 좌표 압축
# 만약 정확한 값이 필요 없고 값의 대소 관계만 필요하다면, 모든 수를 0 이상 N 미만의 수로 바꿀 수 있습니다.
n = int(input())
points = list(map(int, input().split()))

arr = sorted(list(set(points)))
dic = {arr[i]: i for i in range(len(arr))}

for i in points:
    print(dic[i], end=' ')
