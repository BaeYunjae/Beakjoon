#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, b;
	cin >> n >> m >> b;

	int arr[257] = { 0 };
	for (int i = 0; i < n * m; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}

	// 투포인터
	int front = 0, back = 256, nowTime = 0;
	while (front != back) {
		if (arr[front] == 0) {
			front++;
			continue;
		}

		if (arr[back] == 0) {
			back--;
			continue;
		}

		int de = -1;

		if (arr[front] > b || arr[front] > arr[back] * 2) {
			b += arr[back];
			arr[back - 1] += arr[back];
			nowTime += arr[back--] * 2;
		}
		else {
			b -= arr[front];
			arr[front + 1] += arr[front];
			nowTime += arr[front++];
		}
	}
	cout << nowTime << " " << front;
}