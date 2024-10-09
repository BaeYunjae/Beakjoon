#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[51];

int possible(string a, string b){
    int cnt = 0;
    
    for (int i = 0; i < a.length(); i++){
        if (a[i] != b[i]) cnt++;
        if (cnt > 1) return 0;
    }
    return 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;
    
    string temp;
    int num;
    
    q.push(make_pair(begin, 0));
    while(!q.empty()){
        temp = q.front().first;
        num = q.front().second;
        q.pop();
        
        if (temp.compare(target) == 0){
            answer = num;
            break;
        }
        
        for (int i = 0; i < words.size(); i++){
            if (visited[i]) continue;
            
            if (possible(temp, words[i])){
                visited[i] = 1;
                q.push(make_pair(words[i], num + 1));
            }
        }
    }
    
    return answer;
}