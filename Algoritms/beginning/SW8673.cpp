#include<iostream>
#include<queue>

using namespace std;
queue<int> v1;
queue<int> v2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int people = 1;
	long long ans = 0;
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			people = people << 1;
		}
		for (int i = 0; i < people; i++) {
			int tmp; cin >> tmp;
			v1.push(tmp);
		}
		while (1) {
			if (v1.size() == 1) {
				v1.pop();
				break;
			}
			if (v2.size() == 1) {
				v2.pop();
				break;
			}
			if (!v1.empty()) {
				while (!v1.empty()) {
					int a, b;
					a = v1.front(); v1.pop();
					b = v1.front(); v1.pop();
					if (a > b) {
						ans += a - b;
						v2.push(a);
					}
					else {
						ans += b - a;
						v2.push(b);
					}
				}
			}
			else if (!v2.empty()) {
				while (!v2.empty()) {
					int a, b;
					a = v2.front(); v2.pop();
					b = v2.front(); v2.pop();
					if (a > b) {
						ans += a - b;
						v1.push(a);
					}
					else {
						ans += b - a;
						v1.push(b);
					}
				}
			}
		}
		cout <<"#"<<t<<' '<< ans << '\n';
		ans = 0;
		people = 1;
		
	}
}