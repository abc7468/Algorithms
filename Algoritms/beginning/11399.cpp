#include<iostream>
#include<algorithm>
using namespace std;
int person[1001];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> person[i];
	}
	sort(person, person + N);
	long long sum = 0;
	long long k = 0;
	for (int i = 0; i < N; i++) {
		sum += person[i];
		k += sum;
	}
	cout << k<<'\n';
}