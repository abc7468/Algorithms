#include<iostream>
#include<string>
using namespace std;

int map[101][100];
int des[101][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N;
void dfs(int val, int x, int y) {
	des[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (des[nx][ny] == false && map[nx][ny] == val) {
				dfs(val, nx, ny);
			}
		}
	}
}

int cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			map[i][j] = input[j] - 'A';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (des[i][j] == false) {
				dfs(map[i][j], i, j);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (map[i][j] == 17) {
				map[i][j] = 6;
			}
			des[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (des[i][j] == false) {
				dfs(map[i][j], i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';

}