#include<iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int count = 0;
	while (1) {

		if (N % 5 == 0) {
			count = count + N / 5;
			break;
		}

		N = N - 3;
		count++;
		if (N == 0) {
			break;
		}
		if (N < 0) {
			cout << "-1" << '\n';
			return 0;
		}
	}
	cout << count << '\n';
}