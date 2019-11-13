#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> num;
vector<int> oper;
int max_ = -987654321;
int min_ = 987654321;
void solve() {
	int tmp = num[0];
	for (int i = 0; i < N - 1; i++) {
		if (oper[i] == 0) {
			tmp = tmp + num[i + 1];
		}
		else if (oper[i] == 1) {
			tmp = tmp - num[i + 1];
		}
		else if (oper[i] == 2) {
			tmp = tmp * num[i + 1];
		}
		else if (oper[i] == 3) {
			tmp = tmp / num[i + 1];
		}
	}
	if (tmp > max_)max_ = tmp;
	if (tmp < min_)min_ = tmp;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		num.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			oper.push_back(i);
		}
	}
	do {
		solve();
	} while (next_permutation(oper.begin(), oper.end()));
	cout << max_ << '\n' << min_ << '\n';
}