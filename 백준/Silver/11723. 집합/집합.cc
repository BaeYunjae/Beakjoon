#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m;
	cin >> m;

	int DAT[21] = { 0 };

	while (m--) {
		string cmd;
		cin >> cmd;

		int x;
		if (cmd == "add") {
			cin >> x;
			if (DAT[x] == 0) DAT[x] = 1;
		}
		else if (cmd == "remove") {
			cin >> x;
			if (DAT[x] == 1) DAT[x] = 0;
		}
		else if (cmd == "check") {
			cin >> x;
			cout << DAT[x] << "\n";
		}
		else if (cmd == "toggle") {
			cin >> x;
			DAT[x] ^= 1;
		}
		else if (cmd == "all") {
			for (int i = 1; i <= 20; i++) {
				DAT[i] = 1;
			}
		}
		else if (cmd == "empty") {
			for (int i = 1; i <= 20; i++) {
				DAT[i] = 0;
			}
		}
	}
}