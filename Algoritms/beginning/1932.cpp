#include<iostream>
#include<algorithm>
using namespace std;

int a[501][501];
long long sum[501][501];


int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[j][i];
		}
	}
	sum[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				sum[j][i] = a[j][i] + sum[j][i - 1];
			}
			else if (j == i) {
				sum[j][i] = a[j][i] + sum[j - 1][i - 1];
			}
			else {
				if (sum[j - 1][i - 1] > sum[j][i - 1]) {
					sum[j][i] = sum[j - 1][i - 1] + a[j][i];
				}
				else {
					sum[j][i] = sum[j][i - 1] + a[j][i];
				}
			}

		}
	}
	long long cmp=0;
	for (int i = 0; i < n; i++) {
		if (cmp < sum[i][n - 1]) {
			cmp = sum[i][n-1];
		}
	}
	cout << cmp<<'\n';

}