#include<iostream>
using namespace std;
int DP[91];
int main() {
	int N;
	cin >> N;
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	if (N == 1) {
		cout << "1" << "\n";
		return 0;
	}
	if (N == 2) {
		cout << "2" << "\n";
		return 0;
	}
		
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 2] + DP[i - 1];
	}
	cout << DP[N] << "\n";
}