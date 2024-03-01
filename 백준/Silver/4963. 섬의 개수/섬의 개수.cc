#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

int w, h;
int map[51][51];
bool visited[51][51];

int dy[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

void init()
{
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
}

void bfs(int sy, int sx)
{
	queue<Node> q;

	q.push({ sy, sx });
	visited[sy][sx] = true;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (map[ny][nx] == 0 || visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		} 

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		init();

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		int ans = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 0 || visited[i][j]) continue;

				ans++;
				bfs(i, j);
			} 
		}

		cout << ans << "\n";
	}
	

}