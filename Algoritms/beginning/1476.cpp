#include<iostream>

using namespace std;

int main() {
	int E, S, M; cin >> E >> S >> M;
	int e = 1;
	int s = 1;
	int m = 1;
	int cnt = 1;
	while (1) {
		if (E == e && S == s && M == m) break;
		e++;
		s++;
		m++;
		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
		cnt++;
	}
	cout << cnt<<'\n';
}