#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> num;
int numList[10001];

int main() {
	int plus = 0;
	int minus = 0;
	int zero = 0;
	int one = 0;
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> numList[i];
	}
	sort(numList, numList + N);
	for (int i = 0; i < N; i++) {
		if (numList[i] == 0) {
			zero++;
		}
		else if (numList[i] < 0) {
			minus++;
		}
		else if(numList[i]>1){
			plus++;
		}
		else if(numList[i]==1){
			one++;
		}
	}
	long long sum = 0;
	if (zero != 0 && minus % 2 != 0) {
		for (int i = 0; i <= minus; i++) {
			sum += numList[i] * numList[i+1];
			i++;
		}
	}
	else if (zero != 0 && minus % 2 == 0) {
		for (int i = 0; i < minus; i++) {
			sum += numList[i] * numList[i + 1];
			i++;
		}
	}
	else if(zero==0&&minus%2==0){
		for (int i = 0; i < minus; i++) {
			sum += numList[i] * numList[i+1];
			i++;
		}
	}
	else if (zero == 0 && minus % 2 == 1) {
		sum += numList[minus - 1];
		for (int i = 0; i < minus-1; i++) {
			sum += numList[i] * numList[i+1];
			i++;
			
		}
	}
	
	if (plus % 2 != 0) {
		sum += numList[minus + zero + one];
		for (int i = minus + zero + one + 1; i < minus + zero + one + plus; i++) {
			sum += numList[i] * numList[i+1];
			i++;
		}
	}
	else if(plus%2==0){

		for (int i = minus + zero + one; i < minus + zero + one + plus; i++) {
			sum += numList[i] * numList[i+1];
			i++;
		}
	}
	sum = sum + one;
	cout << sum << '\n';

}