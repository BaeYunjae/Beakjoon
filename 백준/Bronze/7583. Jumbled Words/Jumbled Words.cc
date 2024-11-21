#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (1) {
		string sentences;
		vector<string> words;

		getline(cin, sentences);
		if (sentences == "#") break;

		string str = "";
		for (char ch : sentences) {
			if (ch == ' ') {
				words.push_back(str);
				str = "";
				continue;
			}
			str += ch;
		}
		// 마지막 단어
		words.push_back(str);

		for (string word : words) {
			if (word.size() == 1) {
				cout << word << " ";
				continue;
			}
			cout << word[0];
			for (int i = word.size() - 2; i >= 1; i--) {
				cout << word[i];
			}
			cout << word[word.size() - 1] << " ";
		}
		cout << "\n";
	}
}