#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, l;
	cin >> n >> l;

	deque<pair<int, int>> dq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		// 덱 안의 원소는 항상 오름차순이 되어야 한다.
		// 덱 마지막 원소보다 새로운 원소가 클 때까지 pop, 같아도 상관없지 않나?
		while (!dq.empty() && dq.back().second > num) {
			dq.pop_back();
		}

		// 새로운 원소는 무조건 추가
		dq.push_back({ i, num });

		// 앞에 있는 원소들이 확인할 범위보다 작거나 같으면 pop
		while (dq.front().first < i - l + 1) {
			dq.pop_front();
		}

		cout << dq.front().second << " ";
	}

}