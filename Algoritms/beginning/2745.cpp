#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string input; cin >> input;
	int B; cin >> B;
	int tmp;
	long long ans = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] - 'A' >= 0) {
			tmp = ans * B + input[i] - 'A' + 10;
			ans = tmp;
		}
		else {
			tmp = ans * B + input[i] - '0';
			ans = tmp;
		}		
	}
	cout << ans << '\n';
}