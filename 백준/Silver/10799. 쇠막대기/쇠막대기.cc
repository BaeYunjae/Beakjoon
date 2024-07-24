#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	stack<char> st;
	int now = 0;  // 남아있는 열린 괄호
	int sum = 0;  // 현재까지의 쇠막대기 조각 수

	// (((   ()    (     ()    ()    ))     (       ()      )    ()      ))     (      ()      ()     )
	// 123  3(6)  4(7)  4(11) 4(15) 2(15)  3(16)  3(19)  2(19)  2(21)  0(21)  1(22)  1(23)  1(24)    0
	//                                      --------   ---      --				    -      -      -
	//             -	  -     --------------------   ---      --
	// -     -			  -		-
	// -     -			  -		-
	// -     -			  -		--------------------   ---

	

	bool flag = false;
	bool first = false;

	for (char c : input) {

		// 무조건 처음은 열린 괄호
		if (!first && st.empty()) {  // 트러블슈팅2 : 맨 처음이 아닐 때 비어있는 경우 고려 안 함 
			now++;
			sum++;
			st.push(c);
			first = true;
			continue;
		}

		if (c == '(') {
			now++;
			sum++;
			st.push(c);    // 트러블슈팅1 : push를 안 함;;
			flag = false;
		}
		else {
			if (!flag) {
				if (!st.empty()) st.pop();
				flag = true;
				now--;
				sum--;
				sum += now;
			}
			else {
				now--;
			}
		}
	}

	cout << sum;
}