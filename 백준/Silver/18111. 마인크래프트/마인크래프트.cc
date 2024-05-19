#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, b;
	cin >> n >> m >> b;

	int lowest = 21e8;
	int highest = 0;
	vector<int> vect;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			vect.push_back(num);
			lowest = min(lowest, num);
			highest = max(highest, num);
		}
	}

	sort(vect.begin(), vect.end(), greater<>());


	int minTime = 21e8;
	int maxHeight = 0;

	for (int tar = lowest; tar <= highest; tar++) {
		int nowTime = 0;
		int tb = b;
		int flag = 0;
		for (int v = 0; v < vect.size(); v++) {
			if (vect[v] == tar) continue;

			int nowHeight = vect[v];

			// 현재 높이가 더 작을 때
			if (nowHeight < tar) {
				int temp = tar - nowHeight;
				if (tb - temp < 0) {
					flag = 1;
					break;
				}
				tb -= temp;
				nowTime += temp;
			}

			// 현재 높이가 더 클 때
			else if (nowHeight > tar) {
				int temp = nowHeight - tar;
				tb += temp;
				nowTime += temp * 2;
			}

			int de = -1;
		}

		if (flag == 1) continue;

		if (nowTime <= minTime) {
			minTime = nowTime;
			maxHeight = max(maxHeight, tar);
		}
	}

	cout << minTime << " " << maxHeight;
}