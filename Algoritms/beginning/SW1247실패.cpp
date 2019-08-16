#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;


vector<pair<int, int>> map;
vector<int> v[11];
int d[10*9*8*7*6*5*4*3*2];

int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		for (int i = 0; i < N + 2; i++) {
			int x, y; cin >> x >> y;
			map.push_back(make_pair(x, y));
		}
		
		
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				if (j == i) continue;
				v[i].push_back(abs(map[i].first - map[j].first) + abs(map[i].second - map[j].second));
			}
		}

		for(int i =0;i<)




	}



}