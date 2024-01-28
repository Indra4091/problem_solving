#include <iostream>
#include <queue>

using namespace std;

int matrix[101][101] = { 0 };
int visit[101][101] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				matrix[j][i] = -1;
				visit[j][i] = -1;
			}
		}

		int xsize, ysize;
		cin >> xsize >> ysize;

		for (int y = 0; y < ysize; y++) {
			for (int x = 0; x < xsize; x++) {
				char a;
				cin >> a;
				if (a == '0') {
					matrix[y][x] = 0;
				}
				else {
					matrix[y][x] = 1;
				}
			}
		}

		queue<pair<int, int>>q;
		pair<int, int>current = { 0,0 };
		visit[0][0] = 0;
		q.push(current);

		while (!q.empty()) {

			int x = q.front().second;
			int y = q.front().first;

			q.pop();

			for (int z = 0; z < 4; z++) {
				if ((x + dx[z] < xsize && y + dy[z] < ysize) && (x + dx[z] >= 0 && y + dy[z] >= 0)) {
					if (visit[y + dy[z]][x + dx[z]] == -1) {
						visit[y + dy[z]][x + dx[z]] = visit[y][x] + matrix[y + dy[z]][x + dx[z]];
						q.push({ y + dy[z], x + dx[z] });
					}
					else {
						if (visit[y + dy[z]][x + dx[z]] > visit[y][x] + matrix[y + dy[z]][x + dx[z]]) {
							visit[y + dy[z]][x + dx[z]] = visit[y][x] + matrix[y + dy[z]][x + dx[z]];
							q.push({ y + dy[z], x + dx[z] });
						}
					}
				}
			}
		}

		cout << visit[ysize-1][xsize-1] << "\n";
	}
}