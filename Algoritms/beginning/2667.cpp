#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int map[26][26];
int d[26][26];
int ans[25 * 25];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<pair<int,int>> q;
int n;

void bfs(int x, int y, int cnt) {
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
				if (map[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && d[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}
	cout << cnt<<'\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[d[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);

	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << '\n';
	}

}

