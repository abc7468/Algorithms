#include<iostream>
using namespace std;
int a[1000001];
int main() {
	int N; cin >> N;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= N; i++) {
		a[i] = (a[i - 1] + a[i - 2])%15746;
	}

	cout << a[N] << '\n';
}