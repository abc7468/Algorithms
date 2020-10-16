#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int main() {
	vector<int> list;
	int a;
	double abs=0;
	int index=1;
	int N; cin >> N;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 10; i++) {
			cin >> a;
			list.push_back(a);
		}
		sort(list.begin(), list.end());
		for (int i = 1; i < 9; i++) {
			abs = abs + list[i];
		}
		list.clear();
		cout << fixed;
		cout.precision(0);
		cout <<"#"<<index<<" "<< abs/8 << '\n';
		index++;
		abs = 0;
	}
}