#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int level, vector<int> numbers, int target, int now){
    if (level == numbers.size()){
        if (now == target) answer++;
        return;
    }
    
    
    dfs(level + 1, numbers, target, now + numbers[level]);
    dfs(level + 1, numbers, target, now - numbers[level]);
}

int solution(vector<int> numbers, int target) {
    
    dfs(0, numbers, target, 0);
    
    return answer;
}