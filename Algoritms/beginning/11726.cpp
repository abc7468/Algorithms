#include<iostream>

using namespace std;
int main() {
	int a[1001];
	int N; cin >> N;
	a[1] = 1;
	a[2] = 2;
	if (N >= 3) {
		for (int i = 3; i <= N; i++) {
			a[i] = (a[i - 2] + a[i - 1])%10007;
		}
	}

	cout << a[N]<<'\n';
}