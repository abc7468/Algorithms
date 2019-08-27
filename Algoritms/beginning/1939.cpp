#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<pair<int, int>> v[10001];
int d[10001];
vector<long long>des;
bool dfs(int node, int weight ,int dest) {
	d[node] = 1;
	for (int i = 0; i < v[node].size(); i++) {
		if (v[node][i].second >= weight){
			int next = v[node][i].first;
			if (d[next] == 0) {
				dfs(next, weight, dest);
			}
		}
	}
	return d[dest] == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; cin >> N >> M;
	long long big = 0;
	for (int i = 1; i <= M; i++) {
		int A, B, C; cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
		v[B].push_back(make_pair(A, C));
		if (big < C) {
			big = C;
		}
	}
	int factory1, factory2;
	cin >> factory1 >> factory2;
	long long l = 1;
	long long r = big;
	long long ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (dfs(factory1, mid, factory2)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid+1;
		}
		else {
			r = mid-1;
		}
		memset(d, 0, sizeof(d));
	}
	cout << ans << '\n';
}