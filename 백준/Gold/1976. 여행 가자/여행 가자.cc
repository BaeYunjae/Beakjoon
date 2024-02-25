#include <iostream>
using namespace std;

int n, m;
int arr[201];
int map[201][201];
int cities[201];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
}

void init()
{
	for (int i = 1; i <= n; i++) arr[i] = i;
}

int find(int tar)
{
	if (arr[tar] == tar) return tar;

	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;

	arr[t2] = t1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	init();

	// 연결
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 0) continue;

			// 이미 연결되어 있다면 넘어가기
			if (find(i) == find(j)) continue;

			setUnion(i, j);
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> cities[i];
	}

	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (find(cities[i]) != find(cities[j]))
			{
				cout << "NO";
				return 0;
			}
		}
	}


	cout << "YES";
}