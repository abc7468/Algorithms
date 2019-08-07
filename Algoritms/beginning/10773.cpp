#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N; cin >> N;
	vector<long long> a;
	long long sum=0;

	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		if (k != 0) {
			a.push_back(k);
		}
		else {
			if (!a.empty()) {
				a.pop_back();
			}
		}

	}

	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	cout << sum<<'\n';
}