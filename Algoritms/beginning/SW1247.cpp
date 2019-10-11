#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

typedef struct {
	int x;
	int y;
}Coordinate;
int ans = 987654321;
int tmp = 0;
Coordinate house;
Coordinate company;
Coordinate client[12];
vector<int>order;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		
		int N; cin >> N;
		cin >> company.x >> company.y;
		cin >> house.x >> house.y;
		
		for (int i = 0; i < N; i++) {
			cin >> client[i].x >> client[i].y;
			order.push_back(i);
		}
		do {
			tmp = tmp + abs(company.x - client[order[0]].x) + abs(company.y - client[order[0]].y);
			for (int i = 0; i < N-1; i++) {
				tmp = tmp + abs(client[order[i+1]].x - client[order[i]].x) + abs(client[order[i+1]].y - client[order[i]].y);
			}
			tmp = tmp + abs(house.x - client[order[N-1]].x) + abs(house.y - client[order[N-1]].y);
			if (ans > tmp) ans = tmp;
			tmp = 0;

		} while (next_permutation(order.begin(), order.end()));
		cout << "#" << t << ' ' << ans << '\n';
		order.clear();
		
		ans = 987654321;

	}

}