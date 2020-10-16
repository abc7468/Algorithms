#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	long long a; cin >> a;
	vector<long long> input;
	vector<long long> sum;
	for (int i = 0; i < N; i++) {
		long long b;
		cin >> b;
		input.push_back(b);
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i+1; j < N - 1; j++) {
			for (int k = j+1; k < N; k++) {
				long long c = input[i] + input[j] + input[k];
				sum.push_back(c);
			}
		}
	}
	sort(sum.begin(), sum.end());
	for (int i = sum.size()-1; i >=0; i--) {
		if (sum[i] <= a) {
			cout << sum[i] <<'\n';
			return 0;
		}
	}

}