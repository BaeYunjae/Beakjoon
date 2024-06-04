#include <iostream>
#include <string>
using namespace std;

int arr[26]; // 전역에 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	for (auto ch : s)
		arr[ch - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}