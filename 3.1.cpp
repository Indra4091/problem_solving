#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int size;
		cin >> size;

		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;

		int minB = min(min((size - b1), (size - b2)), min(b1 - 1, b2 - 1));
		int minA = min(min((size - a1), (size - a2)), min(a1 - 1, a2 - 1));

		cout << abs(minB - minA) << endl;
	}
}