#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
	char gual;
	int score, level;
};

string str;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> str;

	// 올바르지 않은 괄호열 : ([)], (()()[] => 괄호가 열린 후 다른 종류의 괄호로 닫힘 / 괄호 개수가 안 맞음 
	// ( : 2점, [ : 3점

	stack<Node> s;
	stack<Node> temp;

	for (char c : str) {
		if (s.empty()) {
			if (c == ')' || c == ']') {
				ans = 0;
				break;
			}
			// 처음에 들어가는 괄호는 level 0
			if (c == '(') s.push({ c, 2, 0 });
			else s.push({ c, 3, 0 });
		}
		else {
			// 스택의 top과 짝을 이루지 않을 때
			// 1. 여는 괄호기 들어오면 바로 직전 괄호의 level + 1
			if (c == '(') s.push({ c, 2, s.top().level + 1 });
			else if (c == '[') s.push({ c, 3, s.top().level + 1 });

			// 2. 중간에 다른 닫는 괄호가 등장하면 올바르지 못함
			else if ((s.top().gual == '(' && c == ']') || (s.top().gual == '[' && c == ')')) {
				ans = 0;
				break;
			}

			// 스택의 top과 짝을 이룰 때
			else if ((s.top().gual == '(' && c == ')') || (s.top().gual == '[' && c == ']')) {
				bool flag = false;
				int sum = 0;
				while (!temp.empty() && temp.top().level == s.top().level + 1) {
					flag = true;
					sum += temp.top().score;
					temp.pop();
				}

				if (flag) {
					if (s.top().gual == '(') temp.push({ s.top().gual, 2 * sum, s.top().level });
					else temp.push({ s.top().gual, 3 * sum, s.top().level });
				}
				else {
					temp.push(s.top());
				}

				if (s.size() == 1) {
					ans += temp.top().score;
				}

				s.pop();
			}
		}
	}

	cout << ans;

}