# 스타트와 링크
def backtrack(depth, idx):
    global ans
    if depth == n // 2:  # 선수 중 반을 돌았으면 나머지 반은 다른 팀
        s, l = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:            # 방문한 팀은 스타트팀
                    s += abilities[i][j]
                elif not visited[i] and not visited[j]:  # 방문 안 한 팀은 링크팀
                    l += abilities[i][j]
        ans = min(ans, abs(s - l))
        return

    for i in range(idx, n):              # 선수를 아직 반까지 돌지 않았다면
        if not visited[i]:               # 아직 확인하지 않은 선수면
            visited[i] = 1               # 확인했다고 표시
            backtrack(depth + 1, i + 1)  # 깊이 추가, 인덱스 추가
            visited[i] = 0               # 다시 미확인으로 표시

n = int(input())
abilities = [list(map(int, input().split())) for _ in range(n)]
visited = [0 for _ in range(n)]
ans = 1e9

backtrack(0, 0)
print(ans)
