#include<iostream>
#include<string>
#include<vector>
//try KMP algorithm here

using namespace std;

int main() {
	int test;
	cin >> test;
	for(int t = 0; t < test; t++) {
		bool check = false;
		int lengthMain = 0;
		int lengthSub = 0;
		int pointerStart = 0;
		int stackIdx = 0;
		char last = '0';
		string main;
		string sub;
		vector<char>stack;

		cin >> main >> sub;
		lengthMain = main.size();
		lengthSub = sub.size();
		last = sub[lengthSub - 1];

		for (int i = 0; i < lengthMain; i++) {
			stack.push_back(main[i]);
			pointerStart = stack.size() - lengthSub;
			stackIdx = stack.size() - 1;

			if (stack.back() ==  last && pointerStart >= 0) {
				check = true;
				for (int j = 0; j < lengthSub; j++) {
					if (stack[stackIdx - j] != sub[lengthSub - 1 - j]) {
						check = false;
						break;
					}
				}
			}

			if (check == true) {
				for (int j = 0; j < lengthSub; j++) {
					stack.pop_back();
				}
				check = false;
			}
		}

		if (stack.size() == 0) {
			cout << 0;
		}
		else {
			for (int w = 0; w < stack.size(); w++) {
				cout << stack[w];
			}
		}
		cout << "\n";
	}
}