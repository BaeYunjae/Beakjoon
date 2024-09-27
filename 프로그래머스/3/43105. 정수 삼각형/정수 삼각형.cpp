#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int num = triangle.size();
    
    int dp[501][501] = {0};
    
    // dp 마지막 줄 채우기
    for (int i = 0; i < num; i++){
        dp[num - 1][i] = triangle[num - 1][i];
    }
    
    for (int i = num - 2; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    
    answer = dp[0][0];
    
    return answer;
}