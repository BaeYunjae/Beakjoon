#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	map<string, int> names;

	string name;
	while (n--) {
		cin >> name;

		names[name]++;
	}

	int num = 0;

	while (m--) {
		cin >> name;

		names[name]++;
		if (names[name] == 2) num++;
	}

	cout << num << "\n";

	for (auto it : names) {
		if (it.second == 2) cout << it.first << "\n";
	}

}