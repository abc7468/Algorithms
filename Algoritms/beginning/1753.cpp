#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321
using namespace std;
vector<pair<int, int>> map[20001];
priority_queue <pair<int, int>> pq;

int V, E, K;
int v[20002];
int d[20002];

void dijkstra() {
	d[K] = 0;
	pq.push(make_pair(0, K));
	while (!pq.empty()) {
		int current = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		if (d[current] < dis) continue;
		for (int i = 0; i < map[current].size(); i++) {
			int next = map[current][i].second;
			int nextDis = dis + map[current][i].first;
			if (d[next] > nextDis) {
				d[next] = nextDis;
				pq.push(make_pair(-nextDis, next));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E >> K;

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		map[u].push_back(make_pair(w, v));
	}

	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}
}
