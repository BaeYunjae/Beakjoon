#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int weight[10];
int used[10];

int sumWeight = 0;
int cnt = 0;

int powArr[10];
int factArr[10];

void init()
{
	memset(used, 0, sizeof(used));

	cnt = 0;
	
	// sumWeight 초기화 안 하면 시간초과
	sumWeight = 0;
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
		sumWeight += weight[i];
	}

}

void backtracking(int now, int Left, int Right)
{
	if (now == n)
	{
		cnt++;
		return;
	}

	// 모든 추 무게의 절반을 넘었을 경우 나머지는 넘어가기
	if (Left >= sumWeight - Left)
	{
		cnt += powArr[n - now] * factArr[n - now];
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (used[i] == 1) continue;

		used[i] = 1;

		backtracking(now + 1, Left + weight[i], Right);
		if (Right + weight[i] <= Left) backtracking(now + 1, Left, Right + weight[i]);

		used[i] = 0;
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	powArr[0] = 1;
	factArr[0] = 1;

	for (int i = 1; i <= 9; i++) {
		powArr[i] = powArr[i - 1] * 2;
		factArr[i] = factArr[i - 1] * i;
	}

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		backtracking(0, 0, 0);

		cout << "#" << tc << " " << cnt << "\n";
	}

}