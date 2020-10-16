#include<iostream>
#include<algorithm>
using namespace std;

long long a[10000];
int N;
long long M;
bool check(int num) {
	int val = 0;
	for (int i = 0; i < N; i++) {

		val += a[i] / num;
	}
	if (val >= M) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	long long l = 1;
	long long r = a[N-1];
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid+1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans <<'\n';
}