#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<char, char> um;
    
    um['E'] = 'I';
    um['I'] = 'E';
    um['S'] = 'N';
    um['N'] = 'S';
    um['T'] = 'F';
    um['F'] = 'T';
    um['J'] = 'P';
    um['P'] = 'J';
    
    string str;
    cin >> str;
    
    for (char ch : str){
        cout << um[ch];
    }  
    
}