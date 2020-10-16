#include<iostream>
#include<algorithm>
using namespace std;

int num[100001];

int main() {
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	int tmp = 0;
	int rope = N;
	for (int i = 0; i < N; i++) {
		if (tmp < num[i] * rope) {
			tmp = num[i] * rope;
		}
		rope--;
	}

	cout << tmp<<'\n';
}