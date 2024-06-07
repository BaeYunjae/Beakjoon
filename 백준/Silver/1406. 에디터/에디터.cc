#include <iostream>
#include <string>
using namespace std;

#define MX 600001
char text[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char ch) {
	text[unused] = ch;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;

	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << text[cur];
		cur = nxt[cur];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	string str;
	cin >> str;

	int cursor = 0;
	for (auto s : str) {
		insert(cursor, s);
		cursor++;
	}

	int n;
	cin >> n;

	while (n--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (pre[cursor] == -1) continue;
			cursor = pre[cursor];
		}
		else if (cmd == 'D') {
			if (nxt[cursor] == -1) continue;
			cursor = nxt[cursor];
		}
		else if (cmd == 'B') {
			if (cursor != 0) {
				erase(cursor);
				cursor = pre[cursor];
			}
		}
		else if (cmd == 'P') {
			char ch;
			cin >> ch;

			insert(cursor, ch);
			cursor = nxt[cursor];
		}
	}

	traverse();
}