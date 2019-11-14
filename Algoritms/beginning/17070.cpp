#include<iostream>
#include<vector>
using namespace std;

int N;
int map[18][17];
int d[18][17];
int check = 0;
void solve(int x, int y, int point) {
	if (x == N && y == N) {
		check++;

		return;
	}
	for (int k = 0; k < 3; k++) {
		if (point == 0 && k == 2)continue;
		if (point == 2 && k == 0)continue;
		if (k == 0) {
			if (y < N && map[x][y + 1] != 1) {
				solve(x, y + 1, k);
			}
		}
		else if (k == 1) {
			if (x<N && y < N && map[x][y + 1] == 0 && map[x+1][y + 1] == 0 && map[x+1][y] == 0) {
				solve(x+1, y + 1, k);
			}
		}
		else if (k == 2) {
			if (x < N && map[x+1][y] != 1) {
				solve(x+1, y, k);
			}
		}
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	solve(1, 2, 0);
	cout << check << '\n';
}
