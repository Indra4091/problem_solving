#include<iostream>
#include<vector>
#include<array>
#include<queue>

#define ll long long

using namespace std;

//global variables 
ll matrix[1001][1001] = {0};
bool visited[1001] = {false};

ll key[1001] = {0};
ll parent[1001] = {0};

ll INF = 999999999;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll test;
  cin >> test;
  for (ll t = 0; t < test; t++) {

      ll sum = 0;

    for (ll i = 0; i < 1001; i++) {
      for (ll j = 0; j < 1001; j++) {
        matrix[i][j] = -1;
      }
      key[i] = INF;
      parent[i] = -1;
      visited[i] = false;
    }

    ll place, path;
    cin >> place >> path;

    for (ll i = 0; i < path; i++) {
      ll a, b, t;
      cin >> a >> b >> t;
      matrix[a][b] = t;
      matrix[b][a] = t;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
      ll u = pq.top().second;
      pq.pop();

      if (visited[u] == false) {
        visited[u] = true;
      } else {
        continue; 
      }

      for (ll r = 0; r < place; r++) {
        if (matrix[u][r] > 0) {
          ll v = r;
          ll weight = matrix[u][r];

          if (visited[r] == false && key[v] > weight) {
            key[v] = weight;
            pq.push({key[v], v});
            parent[v] = u; 
          }
        }
      }
    }

    for (ll k = 0; k < place; k++) {
      if (parent[k] >= 0) {
        sum += matrix[parent[k]][k];
      }
    }
    cout << sum << "\n";
  }
}