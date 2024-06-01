#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> set;

void add(int x) {
	for (int i = 0; i < set.size(); i++) {
		if (set[i] == x) return;
	}
	set.push_back(x);
}

void remove(int x) {
	for (int i = 0; i < set.size(); i++) {
		if (set[i] == x) {
			set.erase(set.begin()+i);
		}
	}
}

int check(int x) {
	for (int i = 0; i < set.size(); i++) {
		if (set[i] == x) return 1;
	}
	return 0;
}

void toggle(int x) {
	for (int i = 0; i < set.size(); i++) {
		if (set[i] == x) {
			set.erase(set.begin() + i);
			return;
		}
	}
	set.push_back(x);
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m;
	cin >> m;

	while (m--) {
		string cmd;
		int x;
		cin >> cmd;

		if (cmd == "all") {
			vector<int> tmp;
			for (int i = 1; i <= 20; i++) tmp.push_back(i);
			set = tmp;
		}
		else if (cmd == "empty") set.clear();
		else if (cmd == "add") {
			cin >> x;
			add(x);
		}
		else if (cmd == "remove") {
			cin >> x;
			remove(x);
		}
		else if (cmd == "check") {
			cin >> x; 
			cout << check(x) << "\n";
		}
		else if (cmd == "toggle") {
			cin >> x;
			toggle(x);
		}
	}
}