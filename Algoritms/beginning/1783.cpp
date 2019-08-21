#include<iostream>
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	if (N == 1) {
		cout << "1" << '\n';
	}
	else if (N == 2) {
		if (M <= 8) {
			cout << (M+1) / 2 << '\n';
		}
		else {
			cout << "4" << '\n';
		}
	}
	else if (N > 2) {
		if (M < 5) {
			cout << M << '\n';
		}
		else if(M==5 || M ==6){
			cout << "4" << '\n';
		}
		else {
			cout << M - 2 << '\n';
		}
	}

}