#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> tower;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	// 스택의 첫번째는 초기값
	tower.push({ 100000001, 0 });

	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;

		// 스택 마지막의 높이보다 현재 탑의 높이가 작으면 pop
		while (tower.top().first < height)
			tower.pop();

		// 스택 마지막의 번호 출력
		cout << tower.top().second << " ";

		// 현재 탑의 높이, 현재 탑의 번호 push
		tower.push({ height, i });
	}
}