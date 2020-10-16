#include<iostream>
#include<algorithm>
using namespace std;


int N, M;
int map[9];
int tmp[9];
int visit[9];

void back(int start, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << tmp[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++) {

		if (!visit[i]) {
			tmp[count] = map[i];
			count++;
			visit[i] = true;
			back(i, count);
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

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	sort(map, map + N);
	back(0, 0);


}