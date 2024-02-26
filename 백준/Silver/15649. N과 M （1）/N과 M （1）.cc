#include <iostream>
using namespace std;

int n, m;
int DAT[10];
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
		if (DAT[i] == 1) continue;

		path[level] = i;
		DAT[i] = 1;

		func(level + 1);

		path[level] = 0;
		DAT[i] = 0;
	}
}

int main()
{
	cin >> n >> m;

	func(0);
}