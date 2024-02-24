#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int k, n;
long long arr[10001];

bool isPossible(long long tar)
{
	long long result = 0;

	for (int i = 0; i < k ; i++)
	{
		result += arr[i] / tar;
	}

	if (result >= n) return true;
	return false;
}

int bs(long long start, long long end)
{
	long long mid = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (isPossible(mid)) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return end;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	cout << bs(0, pow(2, 31) - 1);
}