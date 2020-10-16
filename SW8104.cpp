#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v[21];
int a[401];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 400; i++) {
		a[i] = i + 1;
	}
	int testcase = 1;
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M; cin >> N >> M;

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				v[i].push_back(a[cnt++]);
			}
		}
		for (int i = 0; i < N; i++) {
			if (i % 2 != 0) {
				reverse(v[i].begin(), v[i].end());
			}
		}
		cout << "#" << testcase++ << " ";
		int val = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				val += v[j].front();
				v[j].erase(v[j].begin());
			}
			cout << val << ' ';
			val = 0;

		}
		cout << '\n';
		for (int j = 0; j < N; j++) {
			v[j].clear();
		}
	}
}
