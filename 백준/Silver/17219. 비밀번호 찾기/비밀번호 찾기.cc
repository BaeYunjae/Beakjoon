#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> um;
	string site, pwd;

	while (n--) {
		cin >> site >> pwd;
		um[site] = pwd;
	}


	while (m--) {
		cin >> site;
		cout << um[site] << "\n";
	}
}