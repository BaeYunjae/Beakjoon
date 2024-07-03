#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> call;
	vector<string> result;

	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;
		call.push_back(name);
	}

	sort(call.begin(), call.end());

	for (int i = 0; i < m; i++) {
		cin >> name;
		if (binary_search(call.begin(), call.end(), name)) {
			result.push_back(name);
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}