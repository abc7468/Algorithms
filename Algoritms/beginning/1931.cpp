#include<iostream>
#include<algorithm>
using namespace std;

long long tmp;



struct Class {
	long long start;
	long long end;
};

Class cla[100001];

bool cmp(const Class &C1, const Class &C2) {
	if (C1.end < C2.end) {
		return true;
	}
	else if (C1.end == C2.end) {
		return C1.start < C2.start;
	}
	else {
		return false;
	}
}

int main() {
	long long N; cin >> N;
	int count = 0;

	for (long long i = 0; i < N; i++) {
		cin >> cla[i].start >> cla[i].end;
	}
	sort(cla, cla + N, cmp);
	tmp = 0;
	for (long long i = 0; i < N; i++) {
		if (tmp <= cla[i].start) {
			tmp = cla[i].end;
			count++;
		}

	}
	cout << count << '\n';
}