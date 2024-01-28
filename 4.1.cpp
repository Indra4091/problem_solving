#include<iostream>

using namespace std;

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		long long int count;
		cin >> count;

		long long int cPos = 0;
		long long int dPos = 0;
		long long int dSum = 0;
		long long int cSum = 0;

		for (long long int c = 0; c < count; c++) {
			char a;
			cin >> a;
			if (a == 'D') {
				dSum += c - dPos;
				dPos++;
			}
			else if (a == 'C') {
				cSum += c - cPos;
				cPos++;
			}
		}

		if (cSum <= dSum) {
			cout << cSum;
		}
		else {
			cout << dSum;
		}

		cout << endl;
	}
}
