#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string command;
	int x;
	deque<int> dq;

	while (n--) {
		cin >> command;
		if (command == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (command == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (command == "pop_front") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				int front_num = dq.front();
				dq.pop_front();
				cout << front_num << "\n";
			}
		}
		else if (command == "pop_back") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				int back_num = dq.back();
				dq.pop_back();
				cout << back_num << "\n";
			}
		}
		else if (command == "size") {
			cout << dq.size() << "\n";
		}
		else if (command == "empty") {
			if (dq.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (command == "front") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}
		else if (command == "back") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}
	}
}