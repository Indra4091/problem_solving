#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>>pq;
	queue<int>waitlist;
	map<int, int>car_slot;

	int sum = 0;

	int park, car;
	cin >> park >> car;

	for (int t = 0; t < park; t++) {
		int a;
		cin >> a;
		pq.push(a);
	}

	for (int w = 0; w < car * 2; w++) {
		int k;
		cin >> k;

		if (k > 0) {
			if (!pq.empty()) {
				int slot = pq.top();
				sum += slot;
				car_slot.insert({ k, slot });
				pq.pop();
			}
			else {
				waitlist.push(k);
			}
		}
		else {
			k = -1 * k;
			int slot = car_slot[k];
			pq.push(slot);

			if (!waitlist.empty()) {
				int current_car = waitlist.front();
				int current_slot = pq.top();

				waitlist.pop();
				pq.pop();

				sum += current_slot;
				car_slot.insert({ current_car, current_slot });
			}
		}
	}

	cout << sum << "\n";
}