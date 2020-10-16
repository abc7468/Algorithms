#include<iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int val = 0;
	int *list = new int[N + 1];
	int *DP = new int[N + 1];
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < N; i++) {
		DP[i] = list[i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (list[i] > list[j] && DP[j] + list[i] > DP[i]) {
				DP[i] = DP[j] + list[i];
			}
		}
	}


	for (int i = 0; i < N; i++) {
		if (val < DP[i]) val = DP[i];
	}
	cout << val << '\n';

}