#include <iostream>
using namespace std;

int nums[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n) {
		int now = n % 10;
		
		if (now != 6 && now != 9) {
			nums[now]++;
		}
		else {
			if (nums[6] == nums[9])
				nums[now]++;
			else
				nums[nums[6] < nums[9] ? 6 : 9]++;
		}
		n /= 10;
	}

	int maxCnt = 0;
	for (int i = 0; i < 10; i++) {
		if (maxCnt < nums[i]) maxCnt = nums[i];
	}

	cout << maxCnt;
}