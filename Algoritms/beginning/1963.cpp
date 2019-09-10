#include<iostream>
#include<queue>
#include<string>
using namespace std;
bool map[10000];
int d[10000];
queue<int> q;

int change(int now, int index, int value) {
	if (index == 0 && value == 0)return -1;
	string val = to_string(now);
	if (val[index] == value+'0')return -1;
	val[index] = value+'0';
	int returnValue = atoi(val.c_str());
	if (map[returnValue])return -1;
	return returnValue;
}

int main() {
	for (int i = 2; i < 100; i++) {
		int num = 0;
		while (1) {
			num = num + i;
			if (num >= 10000)break;
			map[num] = true;
		}
	}
	int T; cin >> T;
	for (int t = 0; t < T; t++) {

		int N, M; cin >> N >> M;
		if (N == M) {
			cout << "0" << '\n';
			continue;
		}
		q.push(N);
		int cnt = 0;
		d[N] = cnt;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(now, i, j);
					if (next != -1 && d[next] == 0) {
						q.push(next);
						d[next] = d[now] + 1;
					}
				}
			}
		}
		cout << d[M] << '\n';
		for (int i = 0; i < 10000; i++) {
			d[i] = 0;
		}
		
	}
}
