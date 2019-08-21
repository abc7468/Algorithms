#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	int N, M, K;
	cin >> N >> M >> K;

	for (int k = 0; k < K; k++) {
		if (N / M >= 2) {
			N--;
		}
		else {
			M--;
		}
	}
	while (1) {
		M -= 1;
		N -= 2;
		if (N < 0 || M < 0) break;
		cnt++;
	}
	cout << cnt << '\n';

}