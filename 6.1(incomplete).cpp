#include<iostream>
#include<array>
#include<algorithm>
#include<list>
#include<vector>
#define ll long long

using namespace std;

int x = 0;
int matrix[100][100] = { 0 };

void dfsUtil(int node, int count, bool visited[], int& maxCount, list<int>* adj) {
	visited[node] = true;
	for (auto i = adj[node].begin(); i != adj[node].end(); ++i) {
		if (!visited[*i]) {
			count += matrix[*i][node];
			if (count > maxCount) {
				maxCount = count;
				x = *i;
			}
			dfsUtil(*i, count, visited, maxCount, adj);
		}
	}
}


void dfs(int node, int n, list<int>* adj, int& maxCount) {
	bool* visited = new bool[n + 1];
	int count = 0;

	for (int i = 1; i <= n; ++i)
		visited[i] = false;

	dfsUtil(node, count, visited, maxCount, adj);
}


int diameter(list<int>* adj, int n, int s[100]) {

	int maxCount = 0;

	for (int r = 0; r < 100; r++) {
		if (s[r] == 1) {
			for (int j = r + 1; j < 100; j++) {
				if (s[j] == 1) {
					dfs(r, j, adj, maxCount);
				}
			}
		}
	}
	return maxCount;
}


int main() {
	list<int>adj[100];
	int leaf[100] = { 0 };
	int s;
	cin >> s;

	for (int r = 0; r < s - 1; r++) {
		int a;
		int b;
		int c;

		cin >> a >> b >> c;
		matrix[a][b] = s;

		adj[a].push_back(b);
		adj[b].push_back(a);

		leaf[a] = 0;
		leaf[b] = 1;
	}

	cout << diameter(adj, 100, leaf) << "\n";
}