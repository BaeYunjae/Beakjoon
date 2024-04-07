#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// r, c = 1부터 시작

struct Tree {
	int age, r, c;
	bool alive;
};

int n, m, k;
int map[12][12];
int A[12][12];
deque<int> trees[12][12];
vector<pair<int, int>> spread;
vector<pair<pair<int, int>, int>> dead;

int cntTree = 0;

int dr[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dc[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

void input() {
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		cntTree++;
		trees[r][c].push_back(age);
	}
}

void init() {
	// 초기에 양분이 5만큼 들어있음
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 5;
		}
	}
}

void spring() {

	spread.clear();
	dead.clear();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].size() == 0) continue;

			int treeNum = trees[i][j].size();

			while (treeNum--){
				int nowAge = trees[i][j].front();
				trees[i][j].pop_front();
				
				if (map[i][j] >= nowAge) {
					map[i][j] -= nowAge;
					trees[i][j].push_back(nowAge + 1);

					if ((nowAge + 1) % 5 == 0) {
						spread.push_back({ i, j });
					}
				}
				else {
					cntTree--;
					dead.push_back({ {i, j}, nowAge });
				}
			}
		}
	}
}

void summer() {
	for (int i = 0; i < dead.size(); i++) {
		int nowR = dead[i].first.first;
		int nowC = dead[i].first.second;
		int nowAge = dead[i].second;

		map[nowR][nowC] += nowAge / 2;
	}
}

void fall() {
	for (int i = 0; i < spread.size(); i++) {
		int nowR = spread[i].first;
		int nowC = spread[i].second;

		for (int d = 0; d < 8; d++) {
			int nextR = nowR + dr[d];
			int nextC = nowC + dc[d];

			if (nextR < 1 || nextR > n || nextC < 1 || nextC > n) continue;

			cntTree++;
			trees[nextR][nextC].push_front(1);
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] += A[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	init();

	while (k--) {
		spring();
		if (cntTree == 0) break;
		summer();
		fall();
		winter();
	}

	cout << cntTree;
}