#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
pair<int, int> arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		// 끝나는 시간이 가장 빠른 것부터
		// 같다면 시작하는 시간이 가장 빠른 순으로 정렬
		cin >> arr[i].second >> arr[i].first;

	}

	sort(arr, arr + n);

	// 현재 시간
	int currTime = 0;

	// arr의 첫번째 값이 끝나는 시간, 두번째 값이 시작시간
	for (int i = 0; i < n; i++)
	{
		// 현재 회의의 시작하는 시간이 이전 회의 끝나는 시간보다 작으면 넘어가기
		if (currTime > arr[i].second) continue;

		ans++;

		// 현재 회의 끝나는 시간 저장
		currTime = arr[i].first;
	}

	cout << ans;
}