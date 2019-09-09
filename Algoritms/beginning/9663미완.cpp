#include<iostream>
using namespace std;
bool a[15][15];

int n;
bool check(int row, int col) {
	int x = col - 1;
	int y = row - 1;
	while (x >= 0 && y >= 0) {
		if (a[col][row] == true) {
			return false;
		}
	}
	 x = col + 1;
	 y = row - 1;
	while (x < 15 && y >= 0) {
		if (a[col][row] == true) {
			return false;
		}
	}

}

void turn(int row) {
	for(int col = 0; col<15;col++){

	}
}