#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string num;
        cin >> num;

        if (num == "0") break;

        int flag = 0;
        int p1 = 0;
        int p2 = num.length() - 1;

        while (p1 < p2) {
            if (num[p1] == num[p2]) {
                p1++;
                p2--;
            }
            else {
                flag = 1;
                cout << "no\n";
                break;
            }
        }
        if (flag == 1) continue;

        cout << "yes\n";
    }

}