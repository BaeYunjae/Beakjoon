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

	queue<int> q;

	while (n--) {
		cin >> command;

		if (command == "push") {
			cin >> x;
			q.push(x);
		}
		else if (command == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
				continue;
			}
			int f = q.front();
			q.pop();
			cout << f << "\n";
		}
		else if (command == "size") {
			cout << q.size() << "\n";
		}
		else if (command == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (command == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (command == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << q.back() << "\n";
		}
	}
}