#include<iostream>
#include<cstdlib>
using namespace std;

int dn[10] = { 0,1,2,3,4,5,6,7,8,9 };

long long fow(int a, int b) {	
	for (int i = 0; i < b; i++) {
		a *= 10;
	}
	return a;
}

int check_size(long long val) {
	int cnt = 0;
	while (val>0) {

		val /= 10;
		cnt++;
	}
	return cnt - 1;
}



int main() {
	long long big=0;
	long long small=0;
	long long tmp=0;

	long long input; cin >> input;
	int M; cin >> M;
	for (int m = 0; m < M; m++) {
		int a; cin >> a;
		dn[a] = -1;
	}

	int input_size = check_size(input);
	for (int i = 9; i >= 1; i--) {
		if (dn[i] != -1) {
			for (int j = 0; j < input_size-1; j++) {
				small += fow(dn[i], j);
			}
			break;
		}
	}

	for (int i = 1; i <10; i++) {
		if (dn[0] == 0) {
			if (dn[i] != -1) {
				big = fow(dn[i], input_size + 1);
				break;
			}
		}
		else {
			if (dn[i] != -1) {
				for (int j = 0; j < input_size + 2; j++) {
					big += fow(dn[i], j);
				}
				break;
			}
		}
	}
	

}