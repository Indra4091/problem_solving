#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		string s;
		vector<int>stack;
		stack.push_back(0);
		cin >> s;
		int length = s.size();
		int maximum = 0;

		for (int r = 0; r < length; r++) {
			if (s[r] == 'C') {
				stack.push_back(r + 1);
			}
			else {
				stack.pop_back();
				if (stack.empty() == false) {
					maximum = max(maximum, r + 1 - stack.back()); //stack.top()
				}
				else {
					stack.push_back(r + 1);
				}
			}
		}
		cout << maximum << endl;
	}
}