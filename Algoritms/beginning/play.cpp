#include<iostream>
#include<string>
using namespace std;
int main() {
	char chess[9][8];
	char a;
	char F = 'F';
	int val = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> a;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && chess[i][j] == F) {
				val = val+1;
			}
		}
	}
	
	std::cout << val << '\n';
}