#include<iostream>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int w, h;
int map[51][51];
bool d[51][51];
int cnt = 0;
void dfs(int x, int y) {
	d[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k]; int ny = y + dy[k];
		if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
			if (map[nx][ny] == 1 && d[nx][ny] == false) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int K; cin >> w >> h >> K;
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			map[a][b] = 1;
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (map[i][j] == 1 && d[i][j] == false) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt<<'\n';
		cnt = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				map[i][j] = 0;
				d[i][j] = false;
				
			}
		}
	}
}