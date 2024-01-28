#include<iostream>
#include<array>

using namespace std;

int main() {
	int num;
	int max = 10000001;
	cin >> num;
	int mod = 1000000007;
	int* arr = new int[max];

	for (int q = 0; q < max; q++) {
		arr[q] = 0;
	}
	arr[0] = 1;
	arr[1] = 1;

	for (int t = 0; t < num; t++) {
		int student;
		cin >> student;

		if (arr[student] == 0) {

			for (int r = 2; r <= student; r++) {
				arr[r] = arr[r - 1] + arr[r - 2];
				if (arr[r] > mod) {
					arr[r] %= mod;
				}
			}
			cout << arr[student] << endl;
		}
		else {
			cout << arr[student] << endl;
		}
	}
}