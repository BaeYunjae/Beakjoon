#include <iostream>
using namespace std;

int s1, s2, s3;
int DAT[100];
int path[3];

void dfs(int level, int num)
{
	if (level == 3)
	{
		int sumNum = 0;

		for (int i = 0; i < 3; i++)
		{
			sumNum += path[i];
		}

		DAT[sumNum]++;
		return;
	}

	if (num == 1)
	{
		for (int i = 1; i <= s1; i++)
		{
			path[level] = i;

			dfs(level + 1, num + 1);

			path[level] = 0;
		}
	}

	else if (num == 2)
	{
		for (int i = 1; i <= s2; i++)
		{
			path[level] = i;

			dfs(level + 1, num + 1);

			path[level] = 0;
		}
	}

	else if (num == 3)
	{
		for (int i = 1; i <= s3; i++)
		{
			path[level] = i;

			dfs(level + 1, num + 1);

			path[level] = 0;
		}
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s1 >> s2 >> s3;

	dfs(0, 1);

	int maxFreq = 0;
	int ans = 0;

	for (int i = 3; i <= s1 + s2 + s3; i++)
	{
		if (maxFreq < DAT[i])
		{
			maxFreq = DAT[i];
			ans = i;
		}
	}

	cout << ans;
}