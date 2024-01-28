#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
const int SIZE = 1001;

using namespace std;
int matrix[SIZE][SIZE] = { 0 };

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		vector<long long>frendCount;
		vector<long long> frendCheck;
		for (int r = 0; r < SIZE; r++) {
			for (int q = 0; q < SIZE; q++) {
				matrix[r][q] = 0;
			}
			frendCount.push_back(0);
			frendCheck.push_back(0);
		}
		int ppl;
		cin >> ppl;

		for (int i = 1; i <= ppl; i++) {
			int count;
			cin >> count;

			for (int j = 1; j <= count; j++) {
				int frend;
				cin >> frend;

				if (matrix[i][frend] == 0) {
					matrix[i][frend] = 1;
					frendCount[i]++;
					frendCheck[i]++;
				}
				if (matrix[frend][i] == 0) {
					matrix[frend][i] = 1;
					frendCount[frend]++;
					frendCheck[frend]++;
				}
			}
		}

		bool see = false;
		sort(frendCheck.begin(), frendCheck.end());

		if (frendCheck[SIZE - 1] == frendCheck[SIZE - 3]) {
			if (frendCount[1] == frendCheck[SIZE - 1]) {
				see = true;
			}
		}
		else {
			if (frendCount[1] >= frendCheck[SIZE - 3]) {
				see = true;
			}
		}

		if (see == true) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	int test;
//	cin >> test;
//	for (int t = 0; t < test; t++) {
//		int students;
//		cin >> students;
//		for (int s = 0; s < students; s++) {
//			string name;
//			cin >> name;
//		}
//	}
//}
