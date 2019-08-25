#include<iostream>
using namespace std;
int fow[21];
int ha[21];
void solve(int n, int x, int y) {
	if (n == 0)return;
	solve(n - 1, x, 6 - x - y);
	cout << x << " " << y << '\n';
	solve(n - 1, 6 - x - y, y);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;
	fow[0] = 2;
	ha[0] = 1;
	for (int i = 1; i < 21; i++) {
		fow[i] = fow[i-1]*2;
		ha[i] = fow[i] - 1;
	}
	cout << ha[N - 1] << '\n';
	solve(N, 1, 3);


}