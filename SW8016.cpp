#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int N; cin >> N;
	long long* input = new long long[N];
	int index = 1;
	long long a;
	long long b;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < N; i++) {
		if (input[i] == 1) {
			cout << "#" << index << " 1 1" << "\n";
		}
		else {
			a = (input[i] - 1)*(input[i] - 1) * 2 + 1;
			b = input[i] * input[i] * 2 - 1;
			printf("#%d %llu %llu \n",index,a ,b);
		}
		index++;
	}
}