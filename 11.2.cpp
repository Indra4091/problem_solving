#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;

    for (int t = 0; t < test; t++) {
		int length;
		cin >> length;
		
		string s;
		cin >> s;

		vector<int>stack;
		int count = 0;

		for (int r = 0; r < length; r++) {
			if (s[r] == '(') {
				stack.push_back(count);
				count = 0;
			}
			else if (s[r] == ')') {
				count = count * int(s[r + 1] - '0');
				int temp = stack[stack.size() - 1];
				if (count == 0) {		//don't forget this case
					temp++;
				}
				while (count >= 1) {
					temp++;
					count = count / 10;
				}
				stack.pop_back();
				count = temp;
				r++;
			}
			else {
				count++;
			}
		}

		if (count == 0) {
			cout << 1 << "\n";
		}
		else {
			cout << count << "\n";
		}
	}
}
