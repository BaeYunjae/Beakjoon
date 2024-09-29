#include <string>
#include <vector>

using namespace std;

int visited[201] = {0};

void dfs(int n, int i, int level, vector<vector<int>> computers){
    
    for (int j = 0; j < n; j++){
        if (j == i || visited[j] || computers[i][j] == 0) continue;
        visited[j] = 1;
        dfs(n, j, 0, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++){
        if (visited[i] == 0) {
            answer++;
            dfs(n, i, 0, computers);
        };
    }
    
    return answer;
}