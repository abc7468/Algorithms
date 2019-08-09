#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int> a[1002];
bool check[1002];

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	int N; cin >> N;
	int com = 0;
	for (int i = 0; i < N; i++) {
		int T; cin >> T;
		for (int j = 1; j <= T; j++) {
			int num; cin >> num;
			a[j].push_back(num);
			a[num].push_back(j);
		}

		for (int j = 1; j <= T; j++) {
			if (check[j] == 0) {
				dfs(j);
				com++;
			}

			
		}
		cout << com<<'\n';
		for (int j = 1; j <= T; j++) {
			a[j].clear();
		}
		memset(check, 0, sizeof(check));
		com = 0;
	}
	
}