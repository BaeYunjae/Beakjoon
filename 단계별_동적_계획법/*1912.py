# 연속합
input()                            # n은 안 쓰니까 그냥 input만 받기
nums = list(map(int, input().split()))
dp = [nums[0]]                     # dp 리스트
for i in nums[1:]:                 # nums의 2번째 원소부터
    # 현재 원소(i)의 이전 원소(i-1)를 포함하는 최댓값 + 현재 원소(i) 가
    # 현재 원소(i)보다 크면 계속 더해나가는 게 최댓값 유지
    # 현재 원소(i)보다 작으면 현재 원소(i)부터 다시 연속합 시작
    dp.append(max(dp[-1] + i, i))
print(max(dp))
