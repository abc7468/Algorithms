#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1001];
int a[1001];
int k[1001];
int d[1001];
int cnt = 0;
void solve(int node) {
	d[node] = cnt++;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (k[next] == 2 && d[next] == 0) {
			solve(next);
		}
	}
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		int tmp = 0;
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			int s, t; cin >> s >> t;
			v[s].push_back(t);
			v[t].push_back(t);
			k[s]++;
			k[t]++;
			if (k[s] == 3) tmp = s;
			else if (k[t] == 3) tmp = t;
		}
		if (tmp != 0) {
			solve(tmp);
			ans = cnt;
		}
		else {
			ans = N;
		}
		cout <<"#"<<t<<" "<< ans << '\n';
		for (int i = 1; i <= N; i++) {
			d[i] = 0;
			k[i] = 0;
		}
	}

}