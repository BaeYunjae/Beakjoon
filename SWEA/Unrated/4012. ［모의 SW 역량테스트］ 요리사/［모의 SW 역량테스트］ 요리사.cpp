#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int synergy[17][17];
int used[17];
int ans;

void init()
{
	memset(synergy, 0, sizeof(synergy));
	memset(used, 0, sizeof(used));
	ans = 1e9;
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> synergy[i][j];
		}
	}
}

void dfs(int level, int idx)
{
	if (level == N / 2)
	{
		int sumA = 0;
		int sumB = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j) continue;

				if (used[i] == 1 && used[j] == 1) sumA += synergy[i][j];
				else if (used[i] == 0 && used[j] == 0) sumB += synergy[i][j];
			}
		}

		ans = min(ans, abs(sumA - sumB));
		return;
	}

	for (int i = idx; i < N; i++)
	{
		if (used[i] == 1) continue;

		used[i] = 1;
		dfs(level + 1, i + 1);
		used[i] = 0;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		dfs(0, 0);

		cout << "#" << tc << " " << ans << "\n";
	} 

}