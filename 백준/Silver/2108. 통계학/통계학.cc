#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int DAT[8001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		nums.push_back(num);
		DAT[4000 + num]++;
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
	}

	if (round(sum / n) == -0) cout << 0 << "\n";
	else cout << round(sum / n) << "\n";

	sort(nums.begin(), nums.end());

	cout << nums[nums.size()/2] << "\n";

	int maxCnt = 0;
	vector<int> maxCnts;
	for (int i = 0; i < 8001; i++) {
		if (DAT[i] < maxCnt) continue;

		if (DAT[i] == maxCnt) {
			maxCnts.push_back(i - 4000);
		}
		else if (DAT[i] > maxCnt) {
			maxCnt = DAT[i];
			maxCnts.clear();
			maxCnts.push_back(i - 4000);
		}
	}

	if (maxCnts.size() > 1) cout << maxCnts[1] << "\n";
	else cout << maxCnts[0] << "\n";

	cout << (nums[nums.size()-1] - 4000) - (nums[0] - 4000) << "\n";

}