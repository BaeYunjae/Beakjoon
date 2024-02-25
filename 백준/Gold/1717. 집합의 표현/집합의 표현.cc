#include <iostream>
using namespace std;

int arr[1000001];
int n, m;

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

	cin >> n >> m;

	init();

	for (int i = 0; i < m; i++)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 1)
		{
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (cmd == 0)
		{
			setUnion(a, b);
		}
	}

}