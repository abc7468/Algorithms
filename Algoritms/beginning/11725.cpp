#include<iostream>
#include<queue>
#include<vector>
using namespace std;

queue<long long> q;
vector<long long> a[1000001];
bool d[100001];
long long parent[100001];
void bfs(int start) {
	q.push(start); d[start] = true; parent[start] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int next = a[x][i];
			if (d[next] == false) {
				parent[next] = x;
				d[next] = true;
				q.push(next);
			}
		}


	}

}



int main() {
	
	long long N; cin >> N;
	for (int i = 1; i < N; i++) {
		long long b, c; cin >> b >> c;
		a[b].push_back(c);
		a[c].push_back(b);
	}
	bfs(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}