#include<iostream>
using namespace std;
int a[10];
int ca =1;
long long sum = 0;
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int ca = 1;
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		for (int n = 0; n < N; n++) {
			int in; cin >> in;
			a[n] = in;
		}
		sum = a[0];
		for (int i = 1; i < N; i++) {
			if (sum <= 1 || a[i]<=1) {
				sum += a[i];
			}
			else {
				sum *= a[i];
			}
		}
		cout <<"#"<<ca++<<' '<< sum << '\n';
		sum = 0;
	}
}