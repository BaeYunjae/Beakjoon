#include<iostream>
using namespace std;

struct Node {
	int num, paper;
	Node* prev;
	Node* next;
};

int n;
Node balloons[1001];
Node head, tail;

void insert(int index, int data) {
	Node* now = &head;

	for (int i = 0; i < index; i++) {
		now = now->next;
	}

	// 새로운 풍선 생성
	Node* newBalloon = &balloons[index];
	newBalloon->num = index;
	newBalloon->paper = data;
	
	newBalloon->prev = now;
	newBalloon->next = now->next;

	if (index == n) {
		now->next = &balloons[1];
		now->next->prev = newBalloon;
	}

	now->next = newBalloon;

}

void bomb() {
	Node* now = &head;

	int cnt = 1;
	while (cnt != n) {
		// 1. 일단 터뜨림
		now->prev->next = now->next;
		now->next->prev = now->prev;
		cnt++;

		int move = now->paper;

		// 2. 종이 숫자만큼 이동
		if (move > 0) {
			for (int i = 0; i < move; i++) {
				now = now->next;
			}
		}
		else {
			for (int i = move; i < 0; i++) {
				now = now->prev;
			}
		}

		cout << now->num << " ";
		now->prev->next = now->next;
		now->next->prev = now->prev;
	}
}

void init() {
	head.next = &tail;
	tail.prev = &head;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	init();

	int data;

	for (int i = 1; i <= n; i++) {
		cin >> data;
		insert(i, data);
	}

	head = balloons[1];
	tail = balloons[n];

	cout << 1 << " ";
	bomb();
}