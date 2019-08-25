#include<iostream>
using namespace std;


int val[3] = { 0,0,0 };
int map[2188][2188];


void check(int x, int y, int num) {
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;
	for (int i = y; i < y+num; i++) {
		for (int j = x; j < x+num; j++) {
			if (map[j][i] == -1) {
				check1++;
			}
			else if (map[j][i] == 0) {
				check2++;
			}
			else if (map[j][i] == 1) {
				check3++;
			}
		}
	}
	if (check1 == num * num) {
		val[0] += 1;
		return;
	}
	else if (check2 == num * num) {
		val[1] += 1;
		return;
	}
	else if (check3 == num * num) {
		val[2] += 1;
		return;
	}
	else {
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 3; i++) {
				check(x + num / 3 * i, y + num / 3 * j, num / 3);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
		}
	}
	check(0, 0, N);
	cout << val[0] << ' ' << val[1] << ' ' << val[2] << '\n';
}