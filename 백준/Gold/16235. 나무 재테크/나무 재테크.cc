#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 나무 지도
vector<int> tree[11][11];

int n, m, k;
// 양분 지도
int nutr[11][11];
// 추가 양분 배열
int	A[11][11];

// 죽은 나무 개수
// vector의 pop_back은 맨뒤 제거
int die_tree;
// 해당 위치에서 죽은 나무들의 추가 양분들의 합
int die_nutr;

int dr[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dc[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

void input() {
	cin >> n >> m >> k;

	// 추가 양분 배열
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}

	// 심은 나무
	for (int i = 0; i < m; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		tree[r][c].push_back(age);
	}
}

void initNutr() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			nutr[i][j] = 5;
		}
	}
}

void spring_summer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) continue;

			die_tree = 0;
			die_nutr = 0;

			sort(tree[i][j].begin(), tree[i][j].end());

			for (int k = 0; k < tree[i][j].size(); k++) {
				if (nutr[i][j] >= tree[i][j][k]) {
					nutr[i][j] -= tree[i][j][k];
					tree[i][j][k]++;
				}
				else {
					die_tree++;
					die_nutr += tree[i][j][k] / 2;
				}
			}

			// vector는 뒤에서부터 pop
			for (int k = 0; k < die_tree; k++) {
				tree[i][j].pop_back();
			}
			
			// 죽은 나무의 양분 추가
			nutr[i][j] += die_nutr;
		}
	}
}

void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) continue;
			
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int nr = i + dr[d];
						int nc = j + dc[d];

						if (nr < 1 || nr > n || nc < 1 || nc > n) continue;

						tree[nr][nc].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			nutr[i][j] += A[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	initNutr();

	while (k--) {
		spring_summer();
		fall();
		winter();
	}

	int live_tree = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() != 0) live_tree += tree[i][j].size();
		}
	}

	cout << live_tree;
}