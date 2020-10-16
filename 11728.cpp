#include<iostream>
using namespace std;
int a[1000001];
int b[1000001];
int c[2000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}

	long long i = 0;
	long long j = 0;
	long long k = 0;
	while (i < N&&j < M) {
		if (a[i] <= b[j]) {
			c[k] = a[i];
			k++; i++;
		}
		else {
			c[k] = b[j];
			k++; j++;
		}
	}
	while (i < N) {
		c[k] = a[i];
		k++;
		i++;
	}
	while (j < M) {
		c[k] = b[j];
		k++;
		j++;
	}

	for (int i = 0; i < M + N; i++) {
		cout << c[i] << ' ';
	}
	
}