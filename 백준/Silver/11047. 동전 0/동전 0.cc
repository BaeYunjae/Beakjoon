#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int coin[10];
	int cnt = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> coin[i];

	sort(coin, coin + n);

	for (int i = n - 1; i >= 0; i--)
	{
		if (k == 0) break;
		if (coin[i] > k) continue;

		cnt += k / coin[i];

		k %= coin[i];
	}

	cout << cnt;
}