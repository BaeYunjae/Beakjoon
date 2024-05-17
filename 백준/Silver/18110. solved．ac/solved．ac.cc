#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[300001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int percent = round(n * 0.15);

	int sum = 0;
	for (int i = percent; i < n - percent; i++) {
		sum += arr[i];
	}

	int mo = n - (2 * percent);
	float ans = round((float)sum / mo);

	cout << ans;
}