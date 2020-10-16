#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> num;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input; cin >> input;

	sort(input.begin(), input.end());
	if (input[0] != '0') {
		cout << "-1" << '\n';
		
		return 0;
	}
	int sum = 0;
	for (char c : input) {
		sum += c - '0';
	}
	if(sum%3!=0) {
		cout << "-1" << '\n';
		return 0;
	}
	reverse(input.begin(), input.end());
	cout << input << '\n';

}