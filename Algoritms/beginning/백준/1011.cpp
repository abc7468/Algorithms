#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int N; cin >> N;
	long long day=0;
	for (int i = 0; i < N; i++) {
		long long a, b; cin >> a >> b;
		long long c = b - a;
		long long d = floor(sqrt(c));
		c = c - d * d;
		day += d*2-1;
		for (int j = d; j >= 1; j--) {
			while (1) {
				if (c - j >= 0) {
					c = c - j;
					day++;

				}
				else {
					break;
				}
			}
		}
		cout << day << '\n';
		day = 0;
	}

}