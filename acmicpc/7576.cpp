#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001];
int d[1001][1001];
queue<pair<int, int>> q;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int w, h;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx >= 0 && nx < w&&ny >= 0 && ny < h) {
				if (map[nx][ny] == 0 && d[nx][ny] ==0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
}



int main() {
	cin >> w >> h;
	int big=0;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int in; cin >> in;
			map[x][y] = in;
		}
	}
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (map[x][y] == 1) {
				q.push(make_pair(x, y));
			}
		}
	}
	bfs();
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (map[x][y] == 0&&d[x][y]==0) {
				cout << "-1" << '\n';
				return 0;
			}
			else {
				if (big < d[x][y]) {
					big = d[x][y];
				}
			}
		}
	}
	
	cout << big << '\n';

}