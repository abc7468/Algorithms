#include<iostream>
using namespace std;

long long a[102];

int main() {
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	for (int i = 6; i < 101; i++) {
		a[i] = a[i - 1] + a[i - 5];
	}
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int b; cin >> b;
		cout << a[b]<<'\n';
	}
}