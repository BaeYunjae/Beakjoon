#include <iostream>
using namespace std;

int n, m;
int path[10];

void func(int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (level > 0 && path[level - 1] >= i) continue;

		path[level] = i;

		func(level + 1);

		path[level] = 0;
	}
}

int main()
{
	cin >> n >> m;

	func(0);
}