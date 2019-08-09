#include<iostream>
#include<vector>
using namespace std;

vector<int> a[101];
bool check[101];
int cnt = 0;
void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			cnt++;
			dfs(next);
		}
	}
}

int main() {
	int c, d; cin >> c >> d;
	for (int i = 1; i <= d; i++) {
		int e, f; cin >> e >> f;
		a[e].push_back(f);
		a[f].push_back(e);
	}
	dfs(1);
	cout << cnt<<'\n';
}