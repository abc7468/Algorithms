#include<iostream>
using namespace std;
int temp[1000000];
int main() {
	int N;
	int min;
	int max;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> temp[i];
		if (i == 0) {
			min = temp[i];
			max = temp[i];
		}
		if (temp[i] > max) max = temp[i];
		if (temp[i] < min) min = temp[i];
	}
	cout << min << " " << max << "\n";

}

