#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> x;

	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		if (arr[left] + arr[right] == x)
		{
			cnt++;
		}

		else if (arr[left] + arr[right] < x)
		{
			left++;
			right = n;
		}

		right--;
	}

	cout << cnt;
}