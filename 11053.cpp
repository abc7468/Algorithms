#include<iostream>
using namespace std;
int main() {
	int a;
	int val = 1;
	int N; cin >> N;
	int* li = new int[N+1];
	int* tmp = new int[N + 1];
	for (int i = 0; i < N; i++) {
		cin >> a; 
		li[i] = a;
		tmp[i] = 1;
	}
	//이 반복문은 굉장히 조잡한 반복문임..
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (li[i] > li[j]) {
				if (tmp[j] > val) {
					val = tmp[j];
				}
				tmp[i] = val + 1;
			}
		}

		val = 1;
		
		
	}

	for (int i = 0; i < N; i++) {
		if (tmp[i] > val) val = tmp[i];
	}
	cout << val << '\n';

}