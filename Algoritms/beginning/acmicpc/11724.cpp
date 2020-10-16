#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

queue<int> q;
void bfs(int start) {
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
			}
		}
	}
}

int main() {
	int N, M; cin >> N >> M;
	int com = 0;
	for (int i = 1; i <= M; i++) {
		int c, d; cin >> c >> d;
		a[c].push_back(d);
		a[d].push_back(c);
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			bfs(i);
			com++;
		}
	}
	cout << com << '\n';
}