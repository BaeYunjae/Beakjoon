#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	map<int, vector<string>> members;

	int age = 0;
	char name[101] = "";

	while (n--) {
		cin >> age >> name;
		members[age].push_back(name);
	}

	for (auto key : members) {
		for (auto value : key.second) {
			cout << key.first << " " << value << "\n";
		}
	}
}