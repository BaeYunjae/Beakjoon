#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

int N, M, R, C, L;
int map[51][51];
int visited[51][51];
int ans;

int d1[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int d2[2][2] = { -1, 0, 1, 0 };
int d3[2][2] = { 0, -1, 0, 1 };
int d4[2][2] = { -1, 0, 0, 1 };
int d5[2][2] = { 1, 0, 0, 1 };
int d6[2][2] = { 1, 0, 0, -1 };
int d7[2][2] = { -1, 0, 0, -1 };

void init()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	ans = 1;
}

void input()
{
	cin >> N >> M >> R >> C >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void bfs(int sy, int sx)
{
	queue<Node> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		int shape = map[now.y][now.x];
		if (visited[now.y][now.x] == L) return;

		if (shape == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = now.y + d1[i][0];
				int nx = now.x + d1[i][1];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (map[ny][nx] == 0) continue;

				// 상
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;

				// 하
				else if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;

				// 좌
				else if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;

				// 우
				else if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;


				if (visited[ny][nx] != 0) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}


		else if (shape == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = now.y + d2[i][0];
				int nx = now.x + d2[i][1];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

				if (map[ny][nx] == 0 || map[ny][nx] == 3) continue;

				// 상일 때 연결되지 못하는 경우
				if (i == 0 && (map[ny][nx] == 4 || map[ny][nx] == 7)) continue;

				// 하일 때 연결되지 못하는 경우
				else if (i == 1 && (map[ny][nx] == 5 || map[ny][nx] == 6)) continue;

				if (visited[ny][nx] != 0) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}

		else if (shape == 3)
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = now.y + d3[i][0];
				int nx = now.x + d3[i][1];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (map[ny][nx] == 0 || map[ny][nx] == 2) continue;

				// 좌
				if (i == 0 && (map[ny][nx] == 6 || map[ny][nx] == 7)) continue;

				// 우
				else if (i == 1 && (map[ny][nx] == 4 || map[ny][nx] == 5)) continue;

				if (visited[ny][nx] != 0) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}

		else if (shape == 4)
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = now.y + d4[i][0];
				int nx = now.x + d4[i][1];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue; 
				if (map[ny][nx] == 0) continue;

				// 상
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;

				// 우
				else if (i == 1 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;

				if (visited[ny][nx] != 0) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}


		else if (shape == 5)
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = now.y + d5[i][0];
				int nx = now.x + d5[i][1];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (map[ny][nx] == 0) continue;

				// 하
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;

				// 우
				else if (i == 1 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;

				if (visited[ny][nx] != 0) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}

		else if (shape == 6)
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = now.y + d6[i][0];
				int nx = now.x + d6[i][1];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (map[ny][nx] == 0) continue;

				// 하
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;

				// 좌
				else if (i == 1 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;


				if (visited[ny][nx] != 0) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}

		else if (shape == 7)
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = now.y + d7[i][0];
				int nx = now.x + d7[i][1];

				ans++;
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (map[ny][nx] == 0) continue;

				// 상
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;

				// 좌
				else if (i == 1 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;

				if (visited[ny][nx] != 0) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		bfs(R, C);

		int res = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visited[i][j] != 0) res++;
			}
		}

		cout << "#" << tc << " " << res << "\n";
	}

}