#include<iostream>
using namespace std;

int map[10][9];
int d[10][9];
bool ex = false;
bool check(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (d[x][i] == num) {
			return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (d[i][y] == num) {
			return false;
		}
	}
	x = 3*(x / 3);
	y = 3*(y / 3);
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (d[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}

bool print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (d[i][j] == 0)return false;
		}
	}
	ex = true;
	return true;
}

void solve(int x,int y) {
	
	if (print()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << d[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	for (int i = y; i < 9; i++) {
		if (map[x][i] == 0) {
			for (int n = 1; n < 10; n++) {
				if (check(x, i, n)) {
					d[x][i] = n;			
					solve(x, i + 1);
					d[x][i] = 0;
				}
			}
			return;
		}
	}
	if (ex)return;
	solve(x + 1, 0);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			d[i][j] = map[i][j];
		}
	}
	solve(0, 0);
}