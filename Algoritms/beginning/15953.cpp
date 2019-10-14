#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
vector<int> b;
int money1[6] = { 5000000,3000000,2000000,500000,300000,100000 };
int money2[5] = { 5120000,2560000,1280000,640000,320000 };
int cnt = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	a.push_back(0);
	b.push_back(0);
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < i; j++) {
			a.push_back(money1[i-1]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < cnt; j++) {
			b.push_back(money2[i]);
		}
		cnt = cnt << 1;
	}
	while (a.size() != 101) {
		a.push_back(0);
	}
	while (b.size() != 65) {
		b.push_back(0);
	}
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int to1, to2; cin >> to1 >>to2;
		cout << a[to1] + b[to2] << '\n';

	}
}