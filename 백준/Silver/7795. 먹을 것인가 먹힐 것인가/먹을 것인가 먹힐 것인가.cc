#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int N, M;
int A[20001];
int B[20001];
int ans = 0;

void init()
{
	ans = 0;

	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
}

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + M);
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i] <= B[j]) break;
			ans++;
		}
	}
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
		input();

		solve();

		cout << ans << "\n";
	}
}