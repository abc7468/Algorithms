#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;


int N, M;
int map[9];
int tmp[9];
int check[9];
int visit[9];
vector<int> value;
set<vector<int>> s;



void back(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			s.insert(value);
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		count++;
		value.push_back(map[i]);
		back(count);
		value.pop_back();
		count--;
	}
}

set<vector<int>>::iterator iter;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	//sort(map, map + N);
	back(0);

	for (auto k : s) {
		for (auto t : k) printf("%d ", t);
		printf("\n");
	}


}