#include<iostream>
#include<string>
using namespace std;

char map[21][20];
int d[27];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int W;
int H;
int MAX=0;
void dfs(int x, int y, int cnt) {
	if (cnt > MAX)MAX = cnt-1;
	int val = map[x][y] - 'A';
	
	for (int k = 0; k < 4; k++) {
		int kx = x + dx[k];
		int ky = y + dy[k];
		if (kx >= 0 && kx < H&&ky >= 0 && ky < W) {
			if (d[val] == 0) {
				d[val] = 1;
				dfs(kx, ky, cnt+1);
				d[val] = 0;
			}
		}
	}

}

int main() {
	string tmp;
	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		cin >> tmp;
		for (int j = 0; j < W; j++) {
			map[i][j] = tmp[j];
		}
	}
	if (H == 1 && W == 1) {
		cout << 1 << '\n';
		return 0;
	}
	dfs(0, 0, 1);
	cout << MAX << '\n';


}


