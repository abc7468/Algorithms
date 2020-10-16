#include<iostream>
#include<string>
using namespace std;

int main() {
	int N; cin >> N;

	while (N--) {
		int cmp = 0;

		string input; cin >> input;
		string tmp;
		for (int i = 0; i < input.size(); i++) {
			tmp = input[i];
			if (tmp == "(") {
				cmp++;
			}
			if (tmp == ")") {
				cmp--;
			}
			if (cmp < 0) {
				cout << "NO" << '\n';
				cmp = -1;
				break;
			}
		}
		if (cmp == 0) {
			cout << "YES" << '\n';
		}
		else if(cmp!=0&&cmp!=-1) {
			cout << "NO" << '\n';
		}

	}
}