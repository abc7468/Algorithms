#include<iostream>
using namespace std;
bool broken[10];
int check(int channel) {
	int num;
	int len = 0;
	if (channel == 0) {
		if (broken[0])return -1;
		len++;
	}
	while (channel > 0) {
		num = channel % 10;
		if (broken[num]) return -1;
		len++;
		channel = channel / 10;
	}
	return len;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp = 0;
	int ans = 0;
	int channel; cin >> channel;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int broking; cin >> broking;
		broken[broking] = true;
	}
	tmp = channel - 100;
	if (tmp < 0) {
		tmp = -tmp;
	}
	ans = tmp;

	for (int i = 0; i < 1000000; i++) {
		int len = 0;
		int a = channel - i;
		if (a < 0) a = -a;
		len = check(i);
		if (len == -1) {
			continue;
		}
		else {
			len = len + a;
			if (ans > len)
			{
				ans = len;
				//cout << len << '\n';
			}
		}
	}
	if (channel == 0) {
		for (int i = 0; i < 10; i++) {
			if (!broken[i]) {
				ans = 1 + i;
				break;
			}
			ans = 100;
			
		}
	}
	cout << ans << '\n';

}