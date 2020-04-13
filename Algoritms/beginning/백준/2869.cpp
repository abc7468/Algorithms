#include<iostream>
#include<string>
using namespace std;
int main() {
	int A, B;
	long long C;
	cin >> A >> B >> C;
	int D;
	if (C - A <= 0) {
		cout << "1" << '\n';
		return 0;
	}
	D = A - B;
	long long day = (C - A) / D + 1;
	if ((C-A)%D!=0) {
		day = day + 1;
	}
	cout << day << '\n';
}