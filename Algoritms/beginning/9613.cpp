#include<iostream>
using namespace std;
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a%b);
	}
}

int main() {
	int N; cin >> N;
	int I;
	int a, b;
	int *li;
	long long val = 0;
	for (int i = 0; i < N; i++) {
		cin >> I;
		li = new int[I];
		for (int j = 0; j < I; j++) {
			cin >> li[j];
		}
		for (int j = 0; j < I; j++) {
			for (int k = I-1; k > j; k--) {
				val = val + GCD(li[k], li[j]);
			}
		}
		delete li;
		cout << val << '\n';
		val = 0;
	}
}