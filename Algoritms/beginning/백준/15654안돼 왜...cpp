#include<iostream>
#include<algorithm>
using namespace std;
int map[9];
int tmp[9];
bool visit[9];
int N, M;



int check(int start, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << tmp[i];
			if (i + 1 != M) cout << " ";
		}
		cout << "\n";

		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			tmp[count] = map[i];
			visit[i] = true;
			count++;
			check(i, count);
			count--;
			visit[i] = false;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N;i++) {
		cin >> map[i];
	}
	sort(map, map + N);
	check(0, 0);
}

