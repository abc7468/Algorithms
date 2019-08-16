#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[101][101];
int d[101][101];
int w, h;
void bfs(int x, int y) {
	q.push(make_pair(x, y)); d[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx >= 0 && nx < w&&ny >= 0 && ny < h) {
				if (map[nx][ny] == 1 && d[nx][ny]==0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y]+1; //ÀÌÀü²¨ÀÇ +1 ;;;;;
				}
			}
			
		}
	}
}

int main() {
	cin >> w >> h;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
	cout << d[w - 1][h - 1]<<'\n';
}