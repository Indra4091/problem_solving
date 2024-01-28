#include<iostream>
#include<vector>
#include<string>
#include<array>

using namespace std;

int main() {

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int dx[4] = { 0, 0, 1, -1 };
		int dy[4] = { 1, -1, 0, 0 };
		//int map[501][501];
		int visited[501][501];
		int width;
		int height;
		int count = 0;
		pair<int, int>last = { 0,0 };
		vector<pair<int, int>>queue;

		cin >> width >> height;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				char s;
				cin >> s;

				if (s == 'O') {
					//map[j][i] = 0;
					visited[i][j] = 0;
				}
				else if (s == 'X') {
					//map[j][i] = -1;
					visited[i][j] = -1;
				}
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (visited[i][j] == 0) {
					count++;
					visited[i][j] = 1;
					queue.push_back({ i,j });

					while (queue.size() != 0) {
						last = queue.back();
						queue.pop_back();

						for (int k = 0; k < 4; k++) {
							int x = last.second + dx[k];
							int y = last.first + dy[k];

							if (x >= width || y >= height) {
								continue;
							}
							else if (x < 0 || y < 0) {
								continue;
							}
							else if (visited[y][x] != 0) {
								continue;
							}
							else {
								visited[y][x] = 1;
								queue.push_back({ y,x });
							}
						}
					}
				}
			}
		}

		cout << count << "\n";
	}
}