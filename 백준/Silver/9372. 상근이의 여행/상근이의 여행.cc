#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int country[1001];
int result = 0;

void init()
{
	result = 0;
	memset(country, 0, sizeof(country));
}

int find(int tar)
{
	if (country[tar] == tar) return tar;

	int ret = find(country[tar]);
	country[tar] = ret;
	return ret;
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;

	country[t2] = t1;
	result++;
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	
	while (T--)
	{
		init();

		cin >> N >> M;

		for (int i = 1; i <= N; i++) country[i] = i;

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;

			if (find(a) == find(b)) continue;

			setUnion(a, b);
		}

		cout << result << "\n";
	}


}