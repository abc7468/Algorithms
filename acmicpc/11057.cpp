#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int N; cin >> N;
	int DP[1001][10];
	int val=0;
	for (int i = 0; i <= 1000; i++) {
		memset(DP[i], 0, 10 * sizeof(int));
	}

	for (int i = 0; i < 10; i++) {
		DP[0][i] = 0;
		DP[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] = (DP[i][j] + DP[i - 1][k])%10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		val = (val + DP[N][i])%10007;
		
	}
	cout << val << "\n";
	
}