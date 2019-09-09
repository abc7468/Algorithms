#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>>v[1001];
int a[1001];
int d[1001];
int cnt = 1;
void dfs(int node, int cnt) {
	d[node] = cnt;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i].first;
		if (v[node][i].second == 1) {
			v[node][i].second = 0;
			
			dfs(next, cnt + 1);
		}
	}
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		for (int i = 1; i <= N; i++) {
			int b, c; cin >> b >> c;
			v[b].push_back(make_pair(c,1));
			v[c].push_back(make_pair(b,1));
		}
	}
}
