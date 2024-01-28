#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define ll long long

using namespace std;

int matrix[1001][1001] = { 0 };
bool visited[1001] = { false };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {

		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				matrix[i][j] = 0;
			}
			visited[i] = false;
		}

		int place, path;
		cin >> place >> path;

		for (int r = 0; r < path; r++) {
			int a, b, weight; //starts from 0 to N-1
			cin >> a >> b >> weight;

			matrix[a][b] = weight;
			matrix[b][a] = weight;
		}

		int sum = 0;
		//first one weight, second one node
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; //ascending order queue
		pq.push({ 0,0 });

		while (!pq.empty()) {
			int weight = pq.top().first;
			int v = pq.top().second;
			pq.pop();

			if (visited[v] == false) {
				visited[v] = true;
				sum += weight;
			}

			for (int i = 0; i < place; i++) {
				if (matrix[v][i] > 0 && visited[i] == false) {
					pq.push({ matrix[v][i], i });
				}
			}

		}

		cout << sum << "\n";

	}
}