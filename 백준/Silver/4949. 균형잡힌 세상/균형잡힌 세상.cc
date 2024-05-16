#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str = "";

	while (true) {
		getline(cin, str);

		if (str == ".") return 0;

		stack<char> gual;
		bool flag = false;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				gual.push(str[i]);
			}
			
			if (str[i] == ']') {
				if (!gual.empty() && gual.top() == '[') {
					gual.pop();
				}
				else {
					flag = true;
					break;
				}
			}

			else if (str[i] == ')') {
				if (!gual.empty() && gual.top() == '(') {
					gual.pop();
				}
				else {
					flag = true;
					break;
				}
			}
		}

		if (flag || !gual.empty()) cout << "no\n";
		else cout << "yes\n";
	}
}