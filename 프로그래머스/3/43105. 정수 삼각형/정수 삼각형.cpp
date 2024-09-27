#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // 7
    // 3 8
    // 8 1 0
    // 2 7 4 4
    // 4 5 2 6 5
    
    int dp[501][501] = {0};
    dp[0][0] = triangle[0][0];
    dp[1][0] = dp[0][0] + triangle[1][0];
    dp[1][1] = dp[0][0] + triangle[1][1];
    
    for (int i = 2; i < triangle.size(); i++){
        for (int j = 0; j <= i; j++){
            if (j == 0){
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if (j == i){
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }
    }
    
    
    // 마지막 줄만 확인
    for (int i = 0; i < triangle.size(); i++){
        answer = max(dp[triangle.size() - 1][i], answer);
    }
    
    
    return answer;
}