#include<iostream>

using namespace std;
int val[11];
int main() {
	int N; cin >> N;
	int cnt = 0;
	long long a; cin >> a;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		while (a - val[i] >= 0) {
			a -= val[i];
			cnt++;
		}
	}

	cout << cnt<<'\n';
}