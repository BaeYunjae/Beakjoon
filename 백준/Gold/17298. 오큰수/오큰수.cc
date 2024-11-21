#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[1000001];
int ans[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	stack<int> st;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int big = 0;
	if (n >= 1) {
		big = arr[n - 1];
		ans[n - 1] = -1;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) ans[i] = -1;
		else {
			while (!st.empty() && st.top() <= arr[i]) {
				st.pop();
			}
			if (st.empty()) ans[i] = -1;
			else ans[i] = st.top();
		}

		st.push(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}