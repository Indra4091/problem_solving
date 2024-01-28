#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <queue>

#define ll long long

using namespace std;

ll matrix[21][21] = { 0 };
ll list[100001][21] = { 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m, t;	//n-house, m-path, t-time
	cin >> n >> m >> t;

	ll start, finish;
	cin >> start >> finish;

	for (ll r = 0; r < m; r++) {
		ll a, b;
		cin >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	list[t][start] = 1;

	while (t > 0) {
		for (ll r = 1; r <= n; r++) {
			if (list[t][r] != 0) {
				for (ll i = 1; i <= n; i++) {
					if (matrix[r][i] == 1) {
						list[t - 1][i] += list[t][r];
						list[t - 1][i] %= 1000000007;
					}
				}
			}
		}
		t--;
	}

	cout << list[0][finish] << "\n";
}