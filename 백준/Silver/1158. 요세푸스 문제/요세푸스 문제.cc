#include <iostream>
#include <vector>
using namespace std;

int pre[5001], nxt[5001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	// 원형 연결리스트 생성
	int len = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = (i == 1) ? n : i - 1;
		nxt[i] = (i == n) ? 1 : i + 1;
		len++;
	}

	int i = 1;
	// 연결 리스트 순회하며 순열 생성
	for (int cur = 1; len != 0; cur = nxt[cur]) {
		// k번째일 때 제거
		if (i == k) {
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			v.push_back(cur);
			i = 1;
			len--;
		}
		else i++;
	}

	// 요세푸스 순열 출력
	cout << "<";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << ">";
}