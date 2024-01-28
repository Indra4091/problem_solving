#include<iostream>

using namespace std;

int gcd(int bigger, int smaller) {
	int m = bigger % smaller;
	if (m == 0) {
		return smaller;
	}
	else {
		gcd(smaller, m);
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int length;
		int finish;
		int start;
		int leftMove;
		int rightMove;
		int moveCount = 0;

		cin >> length >> finish >> start >> leftMove >> rightMove;
		int move = gcd(leftMove, rightMove);

		if (start == finish) {
			cout << 0 << endl;
			continue;
		}

		if (abs(start - finish) % move != 0) {
			cout << -1 << endl;
			continue;
		}

		while (finish != start) {
			if (start > finish) {
				if (start - leftMove > 0) {
					start -= leftMove;
					moveCount++;
				}
				else if (start + rightMove <= length) {
					start += rightMove;
					moveCount++;
				}
				else {
					moveCount = -1;
					break;
				}
			}
			else if (start < finish) {
				if (start + rightMove <= length) {
					start += rightMove;
					moveCount++;
				}
				else if (start - leftMove > 0) {
					start -= leftMove;
					moveCount++;
				}
				else {
					moveCount = -1;
					break;
				}
			}
		}

		cout << moveCount << endl;
	}
}