#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	long long tmp;
	int index=1;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		vector<long long> list;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			list.push_back(tmp);
		}
		sort(list.begin(), list.end());
		if (list.size() == 1) {
			cout<<"#"<<index<<" " << list[0] * list[0] << '\n';
		}
		else {
			cout << "#" << index << " " << list.front() * list.back() << '\n';
		}
		index++;
	}
}