#include<iostream>
using namespace std;
int BLANK = -1;
int STAR = 1;
int map[6562][6562];

void solve(int x, int y, int n, int shape) {
	if (n < 1) return;

	if (shape == -1) {
		for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {
				map[j][i] = 1;
			}
		}
	}



	int tmp = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				solve(x+tmp*i,y+tmp*j,tmp, BLANK);
			}
			else {
				solve(x + tmp * i, y + tmp * j, tmp, STAR);
			}
		}
	}
	
}

int main() {
	int N; cin >> N;
	solve(0, 0, N, STAR);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 1) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << '\n';
	}
}