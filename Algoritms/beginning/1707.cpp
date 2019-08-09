#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> a[20001];
int check[20001];
int c = 2;
int chk = 0;
void dfs(int node, int c) {
	check[node] =3 - c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == 0) {
			dfs(next, check[node]);
		}
	}
}


int main() {
	memset(check, 0, sizeof(check));
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int V; cin >> V;
		long long E; cin >> E;
		for (int j = 0; j < E; j++) {
			int d, e; cin >> d >> e;
			a[d].push_back(e);
			a[e].push_back(d);
		}
		for (int j = 1; j <= V; j++) {
			if (check[j] == 0) {
				dfs(j, 2);
			}
		}
		for (int j = 1; j <= V; j++) {
			for (int k = 0; k < a[j].size(); k++) {
				int f = a[j][k];
				if (check[j] == check[f]) {
					chk = 1;
					break;
				}
			}
		}
		if (chk == 1) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
		for (int j = 1; j <= V; j++) {
			a[j].clear();
		}
		memset(check, 0, sizeof(check));
		chk = 0;
	}

}
