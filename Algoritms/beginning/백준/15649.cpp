#include<iostream>
#include<vector>
using namespace std;

vector<int>v;
int N, M;
bool check(int n) {
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] > n) {
			return false;
		}
	
	}
	return true;
}

void solve(int num) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i]<<' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		if (check(i)) {
			solve(i);
		}
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		solve(i);
		v.pop_back();
	}
}