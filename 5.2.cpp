#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

//global variables
int dp[1000][1000] = { 0 };
int arr[1000] = { 0 };

int function(int start, int finish, int day) {

	if (start == finish) {
		int check = day * arr[start];
		return day * arr[start];
	}
	else if (dp[start][finish] != 0) {
		int check = dp[start][finish];
		return dp[start][finish];
	}
	else {
		int check = max(function(start + 1, finish, day + 1) + (day * arr[start]), function(start, finish - 1, day + 1) + (day * arr[finish]));
		return dp[start][finish] = check;
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {

		for (int q = 0; q < 1000; q++) {
			arr[q] = 0;
			for (int w = 0; w < 1000; w++) {
				dp[q][w] = 0;
			}
		}

		int count;
		int day = 1;
		cin >> count;

		for (int r = 0; r < count; r++) {
			int a;
			cin >> a;
			arr[r] = a;
		}

		cout << function(0, count - 1, day) << "\n";
	}
}