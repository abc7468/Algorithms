#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool des[1001];
queue<int>q;
vector<int>v[1001];

void dfs(int node) {
	des[node] = true;
	cout << node << ' ';
	for (int i = 0; i < v[node].size(); i++) {
		sort(v[node].begin(), v[node].end());
		int next = v[node][i];
		if (des[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	q.push(start);
	des[start] = true;
	while (!q.empty()) {
		int next = q.front(); q.pop();
		cout << next << ' ';
		for (int i = 0; i < v[next].size(); i++) {
			sort(v[next].begin(), v[next].end());
			if (des[v[next][i]] == false) {
				des[v[next][i]] = true;
				q.push(v[next][i]);
			}
		}
	}

}



int main() {
	int N, M, K; cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int	a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(K);
	for (int i = 0; i < 1001; i++) {
		des[i] = false;
	}
	cout << '\n';
	bfs(K);
	cout << '\n';
}