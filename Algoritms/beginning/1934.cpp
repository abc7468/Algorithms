#include<iostream>
using namespace std;

int GCD(int a, int b) {

		if (b == 0) {
			return a;
		}
		else {
			return GCD(b, a%b);
		}
	
}

int main() {
	int N; cin >> N;
	int a, b,g ; 
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		g = GCD(a, b);
		cout << a * b / g << '\n';
	}


}