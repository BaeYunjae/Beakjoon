#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int n;
string express;
int nums[11];
char opers[10];
int path[10];

queue<int> first_nums;

int idx1 = 0, idx2 = 0;
int maxVal = -21e8;

void input() {
	cin >> n >> express;

	for (int i = 0; i < express.length(); i++) {
		if (express[i] >= '0' && express[i] <= '9') {
			nums[idx1++] = express[i] - '0';
		}
		else {
			opers[idx2++] = express[i];
		}
	}
}

int calculation(int a, int b, char op) {
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else if (op == '*') {
		return a * b;
	}
}


void dfs(int level) {
	if (level == idx1 - 1) {

		int tmp_nums[11] = { 0 };
		char tmp_opers[10] = "";

		// 복사
		for (int i = 0; i < idx1; i++) {
			tmp_nums[i] = nums[i];
		}
		for (int i = 0; i < idx2; i++) {
			tmp_opers[i] = opers[i];
		}

		// 0 -> (0, 1)
		// 1 -> (1, 2)
		// 2 -> (2, 3)
		// 괄호부터 계산
		for (int i = 0; i < idx1 - 1; i++) {
			if (path[i] == 0) continue;

			int ret = calculation(nums[i], nums[i + 1], opers[i]);
			first_nums.push(ret);

			tmp_nums[i] = -1;
			tmp_nums[i + 1] = -1;
			tmp_opers[i] = '/';
		}

		int nowNum = 0;
		int nowOper = -1;
		int nowVal = 0;

		// 처음부터 괄호인 경우
		if (nowOper == -1) {
			if (tmp_nums[nowNum] == -1) {
				nowVal = first_nums.front();
				first_nums.pop();

				nowNum += 2;
				nowOper += 2;
			}
			else {
				nowVal = nums[nowNum];
				nowNum++;
				nowOper++;
			}
		}

		for (int i = nowNum; i < idx1; i++) {
			if (tmp_nums[nowNum] == -1) {
				nowVal = calculation(nowVal, first_nums.front(), opers[nowOper]);
				first_nums.pop();
				nowNum += 2;
				nowOper += 2;
			}
			else {
				nowVal = calculation(nowVal, nums[nowNum], opers[nowOper]);
				nowNum++;
				nowOper++;
			}

			if (nowNum >= idx1 || nowOper >= idx2) break;
		}

		maxVal = max(maxVal, nowVal);
		return;
	}

	path[level] = 0;
	dfs(level + 1);
	if (level > 0 && path[level - 1] == 0) {
		path[level] = 1;
	}
	dfs(level + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	dfs(0);

	cout << maxVal;
}