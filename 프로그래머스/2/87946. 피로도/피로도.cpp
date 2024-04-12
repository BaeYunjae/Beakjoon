#include <string>
#include <vector>

using namespace std;

int answer = -1;
int dunNum;
int used[9];
int path[9];

void dfs(int level, int hp, vector<vector<int>> duns){
    if (level == dunNum){
        int now = hp;
        int cnt = 0;
        for (int i = 0; i < dunNum; i++){
            // 현재 피로도가 던전 최소 필요 이상이면 고
            if (now >= duns[path[i]][0]){
                cnt++;
                now -= duns[path[i]][1];
            }
            // 아니면 넘어가기
            // 만약 현재 cnt + 남은 던전 수가 현재 최댓값과 같거나 작으면
            // 넘어가기
            if ((cnt + (dunNum - 1 - i)) <= answer){
                return;
            }
        }
        
        if (answer < cnt) answer = cnt;
       
        return;
    }
    
    for (int i = 0; i < dunNum; i++){
        if (used[i] == 1) continue;
        
        path[level] = i;
        used[i] = 1;
        dfs(level + 1, hp, duns);
        path[level] = 0;
        used[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dunNum = dungeons.size();
    
    dfs(0, k, dungeons);
    
    return answer;
}