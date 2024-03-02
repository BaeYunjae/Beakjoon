#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Charger {
	int y, x, c, p;
};

int M, A;
int moveInfo[2][101];
Charger chargers[9];
int arr[2][101];  // 충전량 저장 배열
int check[2][9];    // 충전기 접속 가능 여부 저장

int connectA;
int connectB;

int path[2] = { -1, };
int maxCharge = 0;

int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };


// 1. A, B의 위치를 저장하면서 각자 어디를 접속할 수 있는지 확인
// 2. 둘이 같은 곳에 접속하는지 확인 -> 같은 곳이면 p 1/2
// 1 0 1
// 1 0 0
// (0, 0) (2, 0) 비교 -> 최댓값 나오는 경우 저장
// 2개를 더해서 최댓값이면 A, B에 해당 값을 각각 저장

// 1 1
// 1 1
// (0, 0) (0, 1) (1, 0) (1, 1) => 같은 곳 접속하는지 확인 => 어떻게? connectA, B 같으면 1/2

void init()
{
	memset(moveInfo, 0, sizeof(moveInfo));
	memset(chargers, 0, sizeof(chargers));
	memset(arr, 0, sizeof(arr));

	memset(path, -1, sizeof(path));
	memset(check, 0, sizeof(check));
	connectA = 0;
	connectB = 0;

}

void input()
{
	cin >> M >> A;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> moveInfo[i][j];
		}
	}

	for (int i = 0; i < A; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		chargers[i] = { b, a, c, d };
	}
}

bool checkConnect(int y1, int x1, int y2, int x2, int i)
{
	int calc = abs(y1 - y2) + abs(x1 - x2);
	if (calc <= chargers[i].c)
		return true;
	return false;
}

void findMax(int level, int now)
{
	if (level == 2)
	{
		if (path[0] == path[1] && path[0] != -1)
		{
			if (maxCharge < chargers[path[0]].p)
			{
				maxCharge = chargers[path[0]].p;
				arr[0][now] = chargers[path[0]].p / 2;
				arr[1][now] = chargers[path[1]].p / 2;
			}
		}

		else if (path[0] != path[1])
		{
			int ACharge = 0;
			int BCharge = 0;
			int sumCharge = 0;

			if (path[0] == -1) ACharge = 0;
			else ACharge = chargers[path[0]].p;

			if (path[1] == -1) BCharge = 0;
			else BCharge = chargers[path[1]].p;

			sumCharge = ACharge + BCharge;

			if (maxCharge < sumCharge)
			{
				maxCharge = sumCharge;
				arr[0][now] = ACharge;
				arr[1][now] = BCharge;
			}
		}

		else if (path[0] == -1 && path[1] == -1)
			return;

		return;
	}

	for (int i = 0; i < A; i++)
	{
		if (check[level][i] == 1)
			path[level] = i;
		findMax(level + 1, now);
		path[level] = -1;
	}
}

void dfs(int nowAy, int nowAx, int nowBy, int nowBx, int level)
{
	if (level > M) return;

	for (int i = 0; i < A; i++)
	{
		if (checkConnect(nowAy, nowAx, chargers[i].y, chargers[i].x, i)) check[0][i] = 1;
		else check[0][i] = 0;

		if (checkConnect(nowBy, nowBx, chargers[i].y, chargers[i].x, i)) check[1][i] = 1;
		else check[1][i] = 0;
	}

	maxCharge = 0;
	findMax(0, level);

	int nextAy = nowAy + dy[moveInfo[0][level]];
	int nextAx = nowAx + dx[moveInfo[0][level]];

	int nextBy = nowBy + dy[moveInfo[1][level]];
	int nextBx = nowBx + dx[moveInfo[1][level]];

	dfs(nextAy, nextAx, nextBy, nextBx, level + 1);
	
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

		dfs(1, 1, 10, 10, 0);

		int ans = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j <= M; j++)
			{
				if (arr[i][j] == 0) continue;

				ans += arr[i][j];
			}
		}


		cout << "#" << tc << " " << ans << "\n";
	}

}