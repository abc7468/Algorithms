#include<iostream>
using namespace std;

long long power(long long i) {
	long long val=1;
	for (long long j = 1; j <= i; j++) {
		val = (val * i)%1000000007;
	}
	return val;
}

int main() {
	long long N; cin >> N;
	int index = 1;
	long long val = 0;
	for (int j = 0; j < N; j++) {
		long long A; cin >> A;
		for (long long i = 1; i <= A; i++) {
			val = (val + power(i)) % 1000000007;

		}
		printf("#%d %lld\n",index ++, val);
		val = 0;
	}

}