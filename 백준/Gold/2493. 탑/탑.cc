#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> tower;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;

		// 스택 마지막의 높이보다 현재 탑의 높이가 작으면 pop
		while (!tower.empty() && tower.top().first < height)
			tower.pop();

		if (tower.empty()) cout << 0 << " ";
		else cout << tower.top().second << " ";

		// 현재 탑의 높이, 현재 탑의 번호 push
		tower.push({ height, i });
	}
}