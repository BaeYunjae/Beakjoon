#include <iostream>
using namespace std;

int nums[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (1) {
		nums[n % 10]++;
		n /= 10;
		if (n == 0) break;
	}

	// 1. 6과 9를 제외한 수 중에서 최댓값 찾기
	int maxNum = 0, maxCnt = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		if (maxCnt < nums[i]) {
			maxCnt = nums[i];
			maxNum = i;
		}
	}

	// 2. 최댓값 vs 6과 9
	int sum = nums[6] + nums[9];
	int sumCnt = 0;
	if (nums[6] == nums[9]) sumCnt = nums[6];
	else if (sum % 2 == 0) sumCnt = sum / 2;
	else sumCnt = (sum / 2) + 1;

	cout << (maxCnt > sumCnt ? maxCnt : sumCnt);

}