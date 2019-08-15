#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int w, h;
int map[51][51];
bool d[51][51];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push(make_pair(x, y)); d[x][y] = true;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
				if (map[nx][ny] == 1 && d[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	while (cin >> w >> h) {
		if (w == 0 && h == 0) {
			return 0;
		}
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cin >> map[x][y];
			}
		}
		int cnt = 0;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (map[x][y] == 1 && d[x][y] == false) {
					bfs(x, y);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				map[x][y] = 0;
				d[x][y] = false;
			}
		}
		cnt = 0;


	}
}