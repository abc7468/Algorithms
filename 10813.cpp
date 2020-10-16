#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<int> a;
	int N, M; cin >> N >> M;
	int b, c;
	for (int i = 1; i <= N; i++) {
		a.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> b >> c;
		swap(a[b-1], a[c-1]);
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}