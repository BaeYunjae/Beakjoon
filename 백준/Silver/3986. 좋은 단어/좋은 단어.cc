#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	string word;
	stack<char> st;
	while (n--) {
		cin >> word;
		
		while (!st.empty()) st.pop();
		for (char c : word) {
			if (st.empty() || st.top() != c) st.push(c);
			else st.pop();
		}

		if (st.empty()) ans++;
	}

	cout << ans;
}