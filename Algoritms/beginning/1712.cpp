#include<iostream>
using namespace std;
int main() {
	long long A, B, C; cin >> A >> B >> C;
	long long count=0;
	if (B >= C) {
		cout << "-1" << '\n';
		return 0;
	}
	long long K = A / (C - B);
	cout << K + 1 << '\n';

}