#include<iostream>
#include<vector>
#include<string>
using namespace std;

string input;
int check = 0;
long long max_ = -9876543210;
vector<int> oper;
long long num[11][2];
vector<int> sol;
int N;
int parNum;
long long abc(long long a, long long b, int c) {
	if (c == 0) {
		return a * b;
	}
	else if (c == 1) {
		return a + b;
	}
	else if (c == 3) {
		return a - b;
	}
}
void solve(int limit, int count, int next) {
	if (count == limit) {
		long long ans = 0;
		for (int i = 0; i <= N / 2; i++) {
			if (i == 0 && num[0][1] == 1) {
				ans = abc(num[0][0], num[1][0], oper[0]);
				i++;
				continue;
			}
			else if (i == 0 && num[0][1] == 0) {
				ans = num[0][0];
				continue;
			}
			else {
				if (num[i][1] == 1) {
					ans = abc(ans, abc(num[i][0], num[i+1][0], oper[i]), oper[i - 1]);
					i++;

				}
				else {
					ans = abc(ans, num[i][0], oper[i-1]);
				}
			}
		}
		if (ans > max_)max_ = ans;
		return;
	}
	for (int i = next; i < N/2 ; i++) {
		

		if (num[i - 1][1] == 1) continue;
		check++;
		num[i][1] = 1;
		solve(limit, check, i+1);
		num[i][1] = 0;
		check--;
		
	}



}

int main() {

	cin >> N;
	cin >> input;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			num[i/2][0]=input[i] - '0';
			num[i / 2][1] = 0;
		}
		else {
			oper.push_back(input[i] - '*');
		}
	}
	for (int i = 0; i <= ((N+1)/2)/2; i++) {
		solve(i,0,0);
	}
	cout << max_ << '\n';
}