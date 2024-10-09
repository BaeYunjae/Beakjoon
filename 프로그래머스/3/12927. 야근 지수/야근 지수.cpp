#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 야근 피로도 = 야근 시작 시점 + (남은 일의 작업량)**2
// 1시간 동안 작업량 1만큼 처리 가능
// N시간 동안 야근 피로도 최소화하도록 일할 것
// N시간 일하고 남은 일의 작업량 제곱의 합이 가장 적으면 됨
// works는 20'000 * 50'000 = 1'000'000'000
// n은 1'000'000 
// 정렬, 가장 큰 값부터 1씩 줄인다

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for (int i : works){
        pq.push(i);
    }
    
    while (n--){
        int now = pq.top();
        pq.pop();
        if (now > 0){
            pq.push(now - 1);
        }
        if (pq.empty()) return 0;
    }
    
    while (!pq.empty()){
        int now = pq.top();
        pq.pop();
        
        answer += now * now;
    }
    
    return answer;
}