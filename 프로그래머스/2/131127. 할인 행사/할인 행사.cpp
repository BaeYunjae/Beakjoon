#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
    int start = 0;
    int end = 10;
    
    int answer = 0;
    
    vector<int> copyNums;
    
    while (end < discount.size() + 1)
    {
        int flag = 0;
        
        copyNums.clear();
        for (int w = 0; w < want.size(); w++) copyNums.push_back(number[w]);
        
        for (int w = 0; w < want.size(); w++)
        {
            for (int i = start; i < end; i++)
            {
                if (discount[i] == want[w])
                {
                    copyNums[w]--;
                }
            }
        }
        
        for (int i = 0; i < number.size(); i++)
        {
            if (copyNums[i] > 0) 
            {
                flag = 1;
            }
        }
        
        if (flag == 0) answer++;
        
        start++;
        end++;
    }
    
    return answer;
}