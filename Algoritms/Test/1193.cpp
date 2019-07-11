#include<iostream>
using namespace std;
int main() {
	int N;
	int temp = 1;
	cin >> N;
	while (1) {
		if (N - temp <= 0) {
			if (temp % 2 == 0) {
				cout << N << "/" << temp - N + 1 << "\n";
				return 0;
			}
			else {
				cout << temp - N + 1 << "/" << N << "\n";
				return 0;
			}
		}
		N = N - temp;
		temp++;
	}
}