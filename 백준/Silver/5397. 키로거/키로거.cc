#include <iostream>
#include <string>
using namespace std;

#define MX 1000001
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char ch) {
	dat[unused] = ch;
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
		cout << dat[cur];
		cur = nxt[cur];
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		string str;
		cin >> str;

		unused = 1;
		fill(dat, dat + MX, 0);
		fill(pre, pre + MX, -1);
		fill(nxt, nxt + MX, -1);

		int cursor = 0;

		for (auto c : str) {
			if (c == '<') {
				if (pre[cursor] == -1) continue;
				cursor = pre[cursor];
			}
			else if (c == '>') {
				if (nxt[cursor] == -1) continue;
				cursor = nxt[cursor];
			}
			else if (c == '-') {
				if (cursor != 0) {
					erase(cursor);
					cursor = pre[cursor];
				}
			}
			else {
				insert(cursor, c);
				cursor = nxt[cursor];
			}
		}

		traverse();
	}
}