#include<iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int check=0;
	for (int i = 5; i <= N; i++) {
		int tmp = i;
		while (1) {

			if (tmp % 5 == 0) {
				tmp = tmp / 5;
				check++;
			}
			else {
				break;
			}
		}
	}
	cout << check << '\n';
}