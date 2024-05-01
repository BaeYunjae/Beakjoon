#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++){
		int h, w;
		cin >> h >> w;
		v.push_back({ h, w });
	}

	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				rank++;
			}
		}
		cout << rank << "\n";
	}
}