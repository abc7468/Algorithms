#include<iostream>

using namespace std;

long long a[100001];
long long d[100001];
long long c[100001];
long long cnt = 0;
long long sum = 0;
long long com = 0;
void dfs(long long node, long long com) {
	d[node] = ++cnt;
	c[node] = com;
	long long next = a[node];
	if (d[next] == 0) {
		dfs(next, com);
	}
	else if (next == node) {
		sum += cnt - 1;
		cnt = 0;
	}
	else if (d[next] != 0 && c[next] == c[node]) {
		sum += d[next] - 1;
		cnt = 0;
	}
	else if (d[next] != 0 && c[next] != c[node]) {
		sum += d[node];
		cnt = 0;
	}
}


int main() {
	long long T; cin >> T;
	for (int t = 0; t < T; t++) {
		long long N; cin >> N;
		for (long long i = 1; i <= N; i++) {
			long long input; cin >> input;
			a[i] = input;
		}
		for (long long i = 1; i <= N; i++) {
			if (d[i] == 0) {
				dfs(i,com++);
				cout << com << '\n';
			}
		}
		for (long long i = 1; i <= N; i++) {
			a[i] = 0;
			c[i] = 0;
			d[i] = 0;
		}
		cout << sum << '\n';
		cnt = 0;
		com = 0;
		sum = 0;
	}
	
}