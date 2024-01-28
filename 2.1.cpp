#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int books;
		cin >> books;
		map<string, int>name;
		vector<string>number;

		for (int r = 0; r < books; r++) {
			string n;
			cin >> n;
			name.insert(pair<string, int>(n, r));
			number.push_back(n);
		}

		int checking;
		cin >> checking;

		for (int i = 0; i < checking; i++) {
			string checkName;
			cin >> checkName;

			if (checkName.size() == 1) {
				char c = checkName[0];
				int convert = int(c - '1');

				if (convert >= 0 && convert < books) {
					cout << number[convert] << "\n";
				}
			}
			else {
				cout << name[checkName] + 1 << endl;
			}
		}
	}
}