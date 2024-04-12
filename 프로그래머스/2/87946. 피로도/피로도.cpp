#include <string>
#include <vector>

using namespace std;

int n;
int answer = -1;

int visited[9];

void dfs(int level, int hp, vector<vector<int>> dungeons){
    if (answer < level){
        answer = level;
    }
    
    for (int i = 0; i < n; i++){
        if (visited[i] || dungeons[i][0] > hp) continue;
        
        visited[i] = 1;
        dfs(level + 1, hp - dungeons[i][1], dungeons);
        visited[i] = 0;
    }
    
}


int solution(int k, vector<vector<int>> dungeons) {
    
    n = dungeons.size();
    
    dfs(0, k, dungeons);
    
    return answer;
}