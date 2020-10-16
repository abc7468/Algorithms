#include<iostream>
using namespace std;


int map[65][65];


void solve(int x, int y, int num) {
	int check0 = 0;
	int check1 = 0;
	for (int i = y; i < y+num; i++) {
		for (int j = x; j <x+ num; j++) {
			if (map[j][i] == 0) {
				check0++;
			}
			else if(map[j][i]==1){
				check1++;
			}
		}
	}
	if (check0 == num * num) {
		cout << "0";
		return;
	}
	else if (check1 == num * num) {
		cout << "1";
		return;
	}
	else {
		cout << "(";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + num / 2 * j, y + num / 2 * i, num / 2);
			}
		}
		cout << ")";
	}
}

int main() {

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	solve(0, 0, N);
	cout << '\n';
}