#include<iostream>
using namespace std;
int map[129][129];
int val[2] = { 0,0 };
void solve(int x, int y, int size) {
	int check1 = 0;
	int check2 = 0;
	for (int j = y; j < y + size; j++) {
		for (int i = x; i < x + size; i++) {
			if (map[i][j] == 0) {
				check1++;
			}
			else if(map[i][j]==1){
				check2++;
			}
		}
	}
	if (check1 == size * size) {
		val[0]++;
		return;
	}
	else if (check2 == size * size) {
		val[1]++;
		return;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solve(x + size / 2 * i, y + size / 2 * j, size / 2);

		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
		}
	}
	solve(0, 0, N);
	cout << val[0] << '\n' << val[1] << '\n';
}