#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;

	vector<int> v;
	while (k--) {
		int num;
		cin >> num;

		if (num == 0) v.pop_back();
		else v.push_back(num);
	}

	long long ans = 0;

	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
	}

	cout << ans;
}