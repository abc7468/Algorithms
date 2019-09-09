#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> v[100001];
int d[100001];
queue<int> q;
int cnt = 0;
void bfs(int node) {
	q.push(node);
	d[node] = cnt;
	while (!q.empty()) {
		int next = q.front(); q.pop();
		for (int i = 0; i<v[next].size(); i++) {
			if (d[v[next][i]] > d[next] + 1||d[v[next][i]]==0) {
				q.push(v[next][i]);
				d[v[next][i]] = d[next] + 1;
			}
		}
	}
}


int main() {
	int N, K; cin >> N >> K;
	if (N == K) {
		cout << "0" << '\n';
		return 0;
	}
	v[0].push_back(1);
	v[1].push_back(0);
	v[1].push_back(2);
	v[100000].push_back(99999);
	for (int i = 2; i <= 99999; i++) {
		if (i <= 50000) { v[i].push_back(2 * i); }
		v[i].push_back(i - 1);
		v[i].push_back(i + 1);
	}

	bfs(N);
	cout << d[K] << '\n';
}