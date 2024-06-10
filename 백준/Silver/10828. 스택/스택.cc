#include <iostream>
#include <string>
using namespace std;

int dat[10001];
int pos = 0;

void push(int x) {
	dat[pos++] = x;
}

int pop() {
	if (pos == 0) return -1;
	pos--;
	return dat[pos];
}

int empty() {
	if (pos == 0) return 1;
	return 0;
}

int top() {
	if (pos == 0) return -1;
	return dat[pos - 1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (cmd == "pop") {
			cout << pop() << "\n";
		}
		else if (cmd == "size") {
			cout << pos << "\n";
		}
		else if (cmd == "empty") {
			cout << empty() << "\n";
		}
		else if (cmd == "top") {
			cout << top() << "\n";
		}
	}

	return 0;
}