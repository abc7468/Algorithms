#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int N, B; cin >> N >> B;
	string ans = "";
	while (N > 0) {
		if (N%B < 10) {
			ans = ans + (char)(N % B + '0');
		}
		else {
			ans = ans + (char)(N%B - 10 + 'A');
		}
		N = N / B;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

}