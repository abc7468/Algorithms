#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321;
using namespace std;


int d[1002];
int N, M, X; //N은 인원수, M은 간선개수, X는 목적지
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> map[1002];
int dijkstra(int startNode, int desNode) {
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	d[startNode] = 0;
	pq.push(make_pair(0, startNode));
	while (!pq.empty()) {
		int current = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();

		if (d[current] < dis)continue;
		for (int i = 0; i < map[current].size(); i++) {
			int next = map[current][i].second;
			int nextDis = dis+map[current][i].first;
			if (nextDis < d[next]) {
				d[next] = nextDis;
				pq.push(make_pair(-nextDis, next));
				
			}
		}
	}
	return d[desNode];
}

int main() {
	int ans = 0;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int u, v, w; cin >> u >> v >> w;
		map[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= N; i++) {
		int a = dijkstra(i, X) + dijkstra(X, i);
		if (a > ans) {
			ans = a;
		}

		
	}
	cout << ans << '\n';
}