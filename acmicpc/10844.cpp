#include<iostream>
using namespace std;


int main() {
	long long DP[101][11];
	long long val=0;
	int N; cin >> N;
	DP[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		DP[1][i] = 1;
	}
	if (N == 1) {
		cout << "9" << "\n";
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				DP[i][j] = DP[i - 1][j + 1];
			}
			else if (j == 9) {
				DP[i][j] = DP[i - 1][j - 1];
			}
			else {
				DP[i][j] = (DP[i - 1][j + 1] + DP[i - 1][j - 1]) % 1000000000;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		val = (val + DP[N][i]) % 1000000000;
	}
	cout << val << "\n";
}