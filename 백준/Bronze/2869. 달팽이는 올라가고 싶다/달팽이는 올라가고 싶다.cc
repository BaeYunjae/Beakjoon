#include <iostream>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;

	int ans = (v - b) / (a - b);
	if ((v - b) % (a - b) > 0) ans++;

	cout << ans;
}