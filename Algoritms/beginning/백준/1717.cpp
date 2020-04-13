#include<iostream>
using namespace std;

int p[1000001];

int Find(int num) {
	if (p[num] == num) {
		return num;
	}
	else {
		return p[num] = Find(p[num]);
	}
}

void Union(int parent, int num) {
	parent = Find(parent);
	num = Find(num);
	if (parent != num) {
		p[num] = parent;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		p[i] = i;
	}

	for (int m = 0; m < M; m++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			Union(b, c);
		}
		if (a == 1) {
			int x = Find(b);
			int y = Find(c);
			if (x == y) {
				cout << "yes" << '\n';
			}
			if (x != y) {
				cout << "no" << '\n';
			}
		}
	}

}