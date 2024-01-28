#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int mat[1000][1000] = { 0 };

int main() {
	int test;
	cin >> test;
	for(int t = 0; t < test; t++) {

		for (int g = 0; g < 1000; g++) {
			for (int o = 0; o < 1000; o++) {
				mat[g][o] = 0;
			}
		}

		int sum = 0;
		int count;
		cin >> count;

		for (int c = 0; c < count; c++) {
			int x, y, w, h;
			cin >> x >> y >> w >> h;

			for (int r = y; r < y + h; r++) {
				for (int j = x; j < x + w; j++) {
					if (mat[r][j] == 0) {
						sum++;
						mat[r][j] = 1;
					}
				}
			}
		}

		cout << sum << "\n";
	}
}