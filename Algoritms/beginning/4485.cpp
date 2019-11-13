#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
struct Node_ {
	int w;
	int x;
	int y;
};
int N;
int d[126][126];
int map[126][126];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
priority_queue <Node_> pq;
bool operator<(Node_ t, Node_ u) {
	return t.w < u.w;
}


void dijkstra() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			d[i][j] = INF;
		}
	}
	Node_ start;
	start.w = -map[0][0];
	start.x = 0;
	start.y = 0;
	d[0][0] = map[0][0];
	pq.push(start);
	while (!pq.empty()) {
		int currentX = pq.top().x;
		int currentY = pq.top().y;
		int dis = -pq.top().w;
		pq.pop();
		if (dis > d[currentX][currentY])continue;
		for (int k = 0; k < 4; k++) {
			int nextX = currentX + dx[k];
			int nextY = currentY + dy[k];
			int nextDis = dis + map[nextX][nextY];
			if (nextX >= 0 && nextX < N&&nextY >= 0 && nextY < N) {
				if (d[nextX][nextY] > nextDis) {
					d[nextX][nextY] = nextDis;
					Node_ node;
					node.w = -nextDis;
					node.x = nextX;
					node.y = nextY;
					pq.push(node);
				}
			}
		}
	}
}


int main() {
	int tk = 1;
	while (cin >> N) {
		if (N == 0) {
			return 0;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}


		dijkstra();
		cout << "Problem " << tk++ << ": " << d[N - 1][N - 1] << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
			}
		}
	}
}