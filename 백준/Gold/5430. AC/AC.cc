// head, tail 바꾸면 순서가 뒤집히지 않을까
// head가 tail보다 크면 head--, head가 tail보다 작으면 head++ 하면 수가 버려질 듯

#include <iostream>
#include <string>
using namespace std;

// 배열에 들어있는 수가 최대 100,000이니까 배열 크기는 2 * 100,000 + 1 = 200,001

const int MX = 100005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void reverse_dat() {
	int tmp = 0;
	tmp = head;
	if (head < tail) {
		head = tail - 1;
		tail = tmp - 1;
	}
	else {
		head = tail + 1;
		tail = tmp + 1;
	}
}

bool delete_first() {
	if (head == tail) return false;
	if (head > tail) head--;
	else {
		head++;
	}
	return true;
}

void print() {
	cout << "[";
	if (head > tail) {
		for (int i = head; i > tail; i--) {
			cout << dat[i];
			if (i != tail + 1) cout << ",";
		}
	}
	else {
		for (int i = head; i < tail; i++) {
			cout << dat[i];
			if (i != tail - 1) cout << ",";
		}
	}

	cout << "]\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		head = MX, tail = MX;

		string cmd;
		cin >> cmd;

		int n;
		cin >> n;

		string arr;
		cin >> arr;

		// 놓친 점
		// 1. 빈 배열일 때, R인 경우에는 error가 아니다.
		// 2. D가 여러 개 들어오는 경우도 있다.
		// 3. arr이 []일 때 넘어가기 말고, arr이 []이 아닐 때 저장하기

		if (arr != "[]") {
			int idx = tail;
			string x = "";
			for (char c : arr) {
				if (c == '[') continue;

				x += c;

				if (c == ',' || c == ']') {
					dat[tail++] = stoi(x);
					x = "";
				}

			}
		}

		bool flag = true;

		for (char now : cmd) {
			if (now == 'R') {
				reverse_dat();
			}
			else if (now == 'D') {
				if (!delete_first()) {
					flag = false;
					cout << "error\n";
					break;
				}
			}
		}

		if (flag) print();
	}


	return 0;
}