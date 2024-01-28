#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;


int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int arr[100001] = { 0 };
		map<string, int>temp;
		temp.insert(pair<string, int>("", 0));
		int students;

		cin >> students;
		for (int s = 1; s <= students; s++) {
			string name;
			cin >> name;

			temp.insert(pair<string, int>(name, s));
		}

		for (int s = 1; s <= students; s++) {
			string name;
			cin >> name;
			arr[temp[name]] = s;
		}

		int furthest = 0;
		int rewardCount = 0;
		for (int r = 1; r <= students; r++) {
			int furthestTemp = max(arr[r], furthest);
			if (furthestTemp != furthest) {
				rewardCount += furthestTemp - furthest - 1;
				furthest = furthestTemp;
			}
		}

		cout << rewardCount << "\n";
	}
}
