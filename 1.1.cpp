#include<iostream>
#include<string>

using namespace std;

int main() {
	int num; 
	cin >> num;
	for (int t = 0; t < num; t++) {
		string s;
		string c;
		int alphabet[26];
		for (int i = 0; i < 26; i++) {
			alphabet[i] = 0;
		}
		cin >> s >> c;

		if (c.size() != s.size()) {
			cout << "F" << endl;
			continue;
		}

		for (unsigned int i = 0; i < s.size(); i++) {
			int a = 'a';
			int x = int(s[i]) - a;
			int y = int(c[i]) - a;

			alphabet[x]++;
			alphabet[y]--;
		}

		for (int t = 0; t < 26; t++) {
			if (alphabet[t] != 0) {
				cout << 'F' << endl;
				break;
			}
			else if (t == 25 && alphabet[t] == 0) {
				cout << 'T' << endl;
			}
		}

	}
}