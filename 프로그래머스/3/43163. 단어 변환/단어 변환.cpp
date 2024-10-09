#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> us;

int len;
int n;
int visited[51];
int minVal = 1e9;

void dfs(string tar, string now, vector<string> words, int idx, int num){
    if (words[idx] == tar){
        minVal = min(minVal, num);
        printf("num: %d \n", num);
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        
        bool flag = false;
        for (int j = 0; j < len; j++){
            if (now[j] != words[i][j]){
                if (!flag) flag = true;
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            visited[i] = 1;
            printf("%s ", words[i].c_str());
            dfs(tar, words[i], words, i, num + 1);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    for (string str: words){
        us.insert(str);
    }
    
    // 2. words에 target이 없으면 0 return 
    if (us.find(target) == us.end()){
        return 0;
    }
    
    // 1. dfs
    len = begin.size();
    n = words.size();
    
    for (int i = 0; i < n; i++){
        bool flag = false;
        for (int j = 0; j < len; j++){
            if (begin[j] != words[i][j]){
                if (!flag) flag = true;
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            visited[i] = 1;
            dfs(target, words[i], words, i, 1);
        }
        printf("\n");
    }
    
    answer = minVal;
    
    return answer;
}