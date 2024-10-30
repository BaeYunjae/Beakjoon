#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int y, x;
};

int n;
char grid[101][101];
char sekyak[101][101];
int visited[101][101];

// 상하좌우 4방향 
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(int sy, int sx, char nowColor, char graph[101][101]) {
    queue<Node> q;
    q.push({ sy, sx });
    visited[sy][sx] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (visited[ny][nx] || graph[ny][nx] != nowColor) continue;

            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    // 그리드 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 그리드에서 초록색도 빨간색으로 변경
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'G') {
                sekyak[i][j] = 'R';
            }
            else {
                sekyak[i][j] = grid[i][j];
            }
        }
    }

    int noSek = 0;  // 적록색약 아닌 사람
    int yesSek = 0; // 적록색약인 사람

    // 일반 그리드에 대해 BFS 수행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                noSek++;
                bfs(i, j, grid[i][j], grid);
            }
        }
    }

    // 방문여부 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    // 적록색약 그리드에 대해 BFS 수행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                yesSek++;
                bfs(i, j, sekyak[i][j], sekyak);
            }
        }
    }

    cout << noSek << " " << yesSek;
}
