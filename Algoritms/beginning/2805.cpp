#include<iostream>
#include<algorithm>
using namespace std;
int N; int len;
int a[1000001];

bool check(int n) {
	long long val = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] - n <= 0) continue;
		else {
			val += a[i] - n;
		}
	}
	return val >= len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> len;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	long long ans = 0;
	long long r = a[N - 1];
	long long l = 0;

	while (l <= r) {
		long long mid = (r + l) / 2;
		if (check(mid)) {
			if (ans < mid) ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
}