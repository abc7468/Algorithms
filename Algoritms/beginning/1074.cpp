#include<iostream>

using namespace std;
int a, b;

int cnt = 0;
int fow(int n) {
	int val = 1;
	for (int i = 0; i < n; i++) {
		val *= 2;
	}
	return val;
}


void solve(int a, int b, int x, int y, int n) {
	if (n < 1) return;
	else if (n == 1) {
		for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {
				if (j == a && i == b) {
					cout << cnt << '\n';
					return;
				}
				cnt++;
			}
		}
	}
	else {
		int tmp = n / 2;
		int val = 0;
		int j =0; int i =0;
		
			if (a < x + tmp) {
				if (b < y + tmp) {
					j = 0; i = 0;
				}
				else if (b >= y + tmp) {
					j = 0; i = 1;
					cnt += n * n / 4;
				}
			}
			else {
				if (b < y + tmp) {
					j = 1; i = 0;
					cnt += n * n / 2;
				}
				else if (b >= y + tmp) {
					j = 1; i = 1;
					cnt += n * n / 4 * 3;
				}

			}
		
		solve(a, b, x + j * tmp, y + i * tmp, tmp);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N>>a>>b;
	solve(a, b, 0, 0, fow(N));
}