#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int bs(int start, int end, int tar)
{
	int mid = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arr[mid] == tar) return 1;

		if (arr[mid] < tar) start = mid + 1;
		else end = mid - 1;
	}

	return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int target;
		cin >> target;

		cout << bs(0, n - 1, target) << "\n";

	}
}
