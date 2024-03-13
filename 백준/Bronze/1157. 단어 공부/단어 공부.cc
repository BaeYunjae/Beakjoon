#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[50] = { 0, };
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		int alpa = str[i] - '0';

		if (str[i] >= 'a')
		{
			alpa -= 32;
		}

		arr[alpa]++;
	}

	int maxCnt = 0;
	int maxAlpa = 0;

	int start = 'A' - '0';
	int end = 'Z' - '0';

 	for (int i = start; i <= end; i++)
	{
		if (arr[i] == 0) continue;

		if (maxCnt < arr[i])
		{
			maxCnt = arr[i];
			maxAlpa = i;
		}
	}

	int cntMax = 0;
	for (int i = start; i <= end; i++)
	{
		if (arr[i] == 0) continue;

		if (arr[i] == maxCnt)
		{
			cntMax++;
			if (cntMax > 1)
			{
				cout << "?";
				return 0;
			}
		}
	}

	cout << char(maxAlpa + '0');
}