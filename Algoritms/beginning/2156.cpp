#include<iostream>
using namespace std;

int d[10001];
int a[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	d[0] = a[0];
	d[1] = a[0] + a[1];
	for (int i = 2; i < N; i++) {
		d[i] = d[i - 1];
		if (d[i] < d[i - 2] + a[i])d[i] = d[i - 2] + a[i];
		if (d[i] < d[i - 3] + a[i] + a[i - 1])d[i] = d[i - 3] + a[i] + a[i - 1];
	}
	cout << d[N-1]<<'\n';
}