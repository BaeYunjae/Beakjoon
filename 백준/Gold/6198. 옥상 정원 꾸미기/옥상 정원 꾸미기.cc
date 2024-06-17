#include <iostream>
using namespace std;

int stack[80001];
int pos = 0;

long long sum = 0;

void push(int x){
    stack[pos++] = x;
}

void pop(){
    pos--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    while (n--){
        int height;
        cin >> height;
        
        while (pos != 0 && stack[pos - 1] <= height){
            pop();
        }
       
        sum += pos;
        push(height);
    }
    
    cout << sum;
}