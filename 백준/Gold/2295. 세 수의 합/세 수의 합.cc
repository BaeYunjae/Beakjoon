#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
vector<int> twoSum;

bool bs(int start, int end, int tar)
{
	int mid = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (twoSum[mid] == tar) return true;

		if (twoSum[mid] > tar) end = mid - 1;
		else if (twoSum[mid] < tar) start = mid + 1;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			twoSum.push_back(arr[i] + arr[j]); 
		}
	}

	sort(twoSum.begin(), twoSum.end());

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if(bs(0, twoSum.size() - 1, arr[i] - arr[j]))
			{
				cout << arr[i];
				return 0;
			}
		}
	}
}