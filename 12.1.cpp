#include<iostream>
#include<vector>
#include<array>

using namespace std;

bool mat[101][101] = { false };
bool visited[101] = { false };
int summary[101] = { 0 };

void dp(int weight, int a) {
	int sum = 0;

	for (int t = 1; t <= weight; t++) {
		if (a == t) {
			continue;
		}
		if (mat[a][t] == true) {
			if (visited[t] == false) {
				visited[t] = true;
				dp(weight, t);
			}
		}
	}

	for (int r = 1; r <= weight; r++) {
		if (r == a) {
			continue;
		}
		if (visited[r] == true) {
			sum++;
		}
	}
	summary[a] = sum;
	return;
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int weight;
		int compare;
		cin >> weight >> compare;

		for (int p = 0; p < 101; p++) {
			for (int q = 0; q < 101; q++) {
				mat[p][q] = false;
			}
			summary[p] = 0;
			visited[p] = false;
		}

		for (int w = 0; w < compare; w++) {
			int a;
			int b;
			cin >> a >> b;		//a is heavier than be
			mat[a][b] = true;
		}

		for (int r = 1; r <= weight; r++) {
			dp(weight, r);
			cout << summary[r] << " ";
			for (int p = 1; p <= weight; p++) {
				visited[p] = false;
				summary[p] = 0;
			}
		}
		cout << "\n";
	}
}