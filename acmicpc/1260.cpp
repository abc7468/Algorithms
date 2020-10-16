#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> a[1001];
queue <int> q;
bool check[1001];
void dfs(int node) {
	check[node] = true;
	cout << node << ' ';
	for (int i = 0; i < a[node].size(); i++) {
		sort(a[node].begin(), a[node].end());
		int k = a[node][i];
		if (check[k] == false) {
			dfs(k);
		}
	}
}

void bfs(int start) {
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << ' ';
		for (int i = 0; i < a[node].size(); i++) {
			sort(a[node].begin(), a[node].end());
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}



int main() {
	int N, M, V; cin >> N >> M >> V;
	for (int i = 1; i <= M; i++) {
		int c, d; cin >> c >> d;
		a[c].push_back(d);
		a[d].push_back(c);
	}
	dfs(V);
	memset(check, false, sizeof(check));

	cout << '\n';
	bfs(V);
}