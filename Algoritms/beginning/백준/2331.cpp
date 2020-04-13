#include<iostream>
#include<vector>
using namespace std;

int check[1000000];

int pow(int a, int p) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans = ans * a;
	}
	return ans;
}

int next(int b, int p) {
	int val = 0;
	while (b > 0) {
		val = val + pow(b % 10, p);
		b = b / 10;
	}
	return val;
}

int dfs(int a, int b, int cnt) {
	if (check[a] == 0) {
		check[a] = cnt;
		int c = next(a, b);
		dfs(c, b, cnt + 1);
	}
	else {
		return check[a] - 1;
	}
}


int main() {
	int A, P; cin >> A >> P;
	cout << dfs(A, P, 1) << '\n';
}