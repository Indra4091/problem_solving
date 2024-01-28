#include<iostream>
#include<vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	vector<int>result;

	for (int t = 0; t < test; t++) {
		int cards1[100001] = { 0 };
		int cards2[100001] = { 0 };

		int n;
		cin >> n;

		int m;
		cin >> m;

		int sum1 = 0;
		int sum2 = 0;

		for (int r = 0; r < m; r++) {
			int a;
			int b;
			cin >> a >> b;

			cards1[a] = 1;
			cards2[b] = 1;
			if (a < b) {
				sum2++;
			}
			else if (a >= b) {
				sum1++;
			}
		}

		int left = n - m;
		int index2 = n;
		int index1Left = 1;
		int index1Right = n;

		while (left > 0) {
			while (cards2[index2] == 1) {
				index2--;
			}

			while (cards1[index1Left] == 1) {
				index1Left++;
			}

			while (cards1[index1Right] == 1) {
				index1Right--;
			}

			cards2[index2] = 1;

			if (index1Right >= index2) {
				sum1++;
				cards1[index1Right] = 1;
			}
			else {
				sum2++;
				cards1[index1Left] = 1;
			}

			left--;
		}

		if (sum1 > sum2) {
			result.push_back(1);
		}
		else {
			result.push_back(0);
		}
	}
	for (int q = 0; q < result.size(); q++) {
		cout << result[q] << "\n";
	}
}

//int main() {
//	int house;
//	cin >> house;
//	int save[10000][10000] = { 0 };
//
//	int pathCount = house - 1;
//	for(int t = 0; t < pathCount; t++) {
//		int house1;
//		int house2;
//		int pathLength;
//
//		cin >> house1 >> house2 >> pathLength;
//		save[house1 - 1][house2 - 1] = pathLength;
//		save[house2 - 1][house1 - 1] = pathLength;
//	}
//
//
//}