#include<iostream>
using namespace std;
int a[500001];
int b[500001];

long long solve(int start, int end) {
	if (start == end)return 0;

	int mid = (start + end) / 2;

	long long ans = solve(start, mid) + solve(mid + 1, end);
	int i = start;
	int j = mid+1;
	int cnt = 0;

	while (i <= mid || j <= end) {
		if (i<=mid&&(j>end || a[i] <= a[j])) {
			
			b[cnt++] = a[i++];
		}
		else {
			ans = ans + (long long)(mid - i + 1);
			b[cnt++] = a[j++];
		}
	}
	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	long long ans = solve(0, N-1);
	cout << ans << '\n';
}