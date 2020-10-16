#include<iostream>
using namespace std;
int n;
int ans = 0;
bool a[15][15];

bool check(int col, int row) {
	
	for (int i = 0; i < n; i++) {
		if (row == i)continue;
		if (a[col][i])return false;
	}

	int x = col - 1; int y = row - 1;
	while (x >= 0 && y >= 0) {
		if (a[x][y]==true) return false;
		x -= 1;
		y -= 1;
	}

	x = col + 1; y = row - 1;
	while (x < n && y >= 0) {
		if (a[x][y]==true) return false;
		x += 1;
		y -= 1;
	}
	return true;
}

void turn(int row) {
	if (row == n) {
		ans++;
	}
	for (int i = 0; i < n; i++) {
		a[i][row] = true;
		if (check(i, row)) {
			turn(row + 1);
		}
		a[i][row] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	turn(0);
	cout << ans << '\n';
}