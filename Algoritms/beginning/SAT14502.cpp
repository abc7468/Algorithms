#include<iostream>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[9][8];
int des[9][8];
int wall = 0;
int tmp = 0;
int ans = 0;
int N, M;

void dfs(int x, int y) {
	des[x][y] = 2;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < N&&ny >= 0 && ny < M) {
			if (des[nx][ny] == 0) {
				dfs(nx,ny);
			}
		}
	}
}

void back(int next) {
	for (int i = next; i < M*N; i++) {
		if (wall < 3) {
			if (des[i / M][i%M] == 0) {
				wall++;
				des[i / M][i%M] = 1;
				back(i + 1);
				des[i / M][i%M] = 0;
				wall--;
			}
		}
		else if (wall == 3) {
			for (int j = 0; j < M*N; j++) {
				if (des[j / M][j%M] == 2) {
					dfs(j / M, j%M);
				}
			}
			for (int j = 0; j < M*N; j++) {
				if (des[j / M][j%M] == 0) {
					tmp++;
				}
			}
			if (ans < tmp)ans = tmp;
			tmp = 0;
			for (int m = 0; m < N; m++) {
				for (int n = 0; n < M; n++) {
					if (map[m][n] == 0 && des[m][n] == 2) {
						des[m][n] = 0;
					}
				}
			}
		}


	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			des[i][j] = map[i][j];
		}
	}
	back(0);
	cout << ans << '\n';

}