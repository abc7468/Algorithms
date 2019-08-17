#include<iostream>
using namespace std;
int main() {
	long long a[12];
	int T; cin >> T;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (int t = 0; t < T; t++) {
		int n; cin >> n;
		if (n >= 4) {
			for (int i = 4; i <= n; i++) {
				a[i] = a[i - 1] + a[i - 2] + a[i - 3];
			}
		}
		cout << a[n] << '\n';

	}
}