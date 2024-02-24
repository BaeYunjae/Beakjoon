#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int Xs[1000001];
int tmp[1000001];
vector<int> arr;

int bs(int start, int end, int target)
{
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (arr[mid] >= target) end = mid;
		else start = mid + 1;
	}

	return start;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> Xs[i];

		tmp[i] = Xs[i];
	}

	sort(tmp, tmp + n);

	for (int i = 0; i < n; i++)
	{
		// 중복 없이 데이터 삽입
		if (arr.size() == 0 || tmp[i - 1] != tmp[i])
			arr.push_back(tmp[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << bs(0, arr.size() - 1, Xs[i]) << " ";
	}
}