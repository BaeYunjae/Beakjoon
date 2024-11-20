#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, string> um;
    um["SONGDO"] = "HIGHSCHOOL";
    um["CODE"] = "MASTER";
    um["2023"] = "0611";
    um["ALGORITHM"] = "CONTEST";
    
    string str;
    cin >> str;
    
    cout << um[str];
}