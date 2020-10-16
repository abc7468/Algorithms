#include<iostream>
using namespace std;
int a[10001];
int N, M;
unsigned long long val;
bool check(long long min) {
	val = 0;
	for (int i = 1; i <= M; i++) {

		val += min / a[i];
	}

	return val < N;
}


int main() {
	cin >> N >> M;
	int cnt = 1;
	for (int i = 1; i <= M; i++) {
		cin >> a[i];
	}
	if (M >= N) {
		cout << N << '\n';
		return 0;
	}

	N = N - M;
	long long l = 0;
	long long r = 9223372036854775807;
	long long ans = 0;
	
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid + 1;
		}
		else {
			r = mid -1;
		}
	}
	N = N  - val;
	cout << val<<'\n'<<ans<<'\n';
	if (N == 0) {
		cout << M <<'\n';
		return 0;
	}
	
	while (1) {
		for (int i = 1; i <= M; i++) {
			if ((ans+1) % a[i] == 0) {
				N--;
			}
			if (N == 0) {
				cout << i << '\n';
				return 0;
			}
		}
		ans++;
	}

	
}