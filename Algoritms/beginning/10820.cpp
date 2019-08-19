#include<string>
#include<iostream>
using namespace std;
int main() {
	string input;
	int tmp[4] = {0,0,0,0};

	while(1) {
		getline(cin, input);
		if (cin.eof()) return 0;
		if (input.size() == 0) continue;
		
		for (int i = 0; i < input.size(); i++) {
			if ((int)(input[i]) >= 65 && (int)(input[i]) <= 90) {
				tmp[1] += 1;
			}
			else if ((int)(input[i]) >= 97 && (int)(input[i]) <= 122) {
				tmp[0] += 1;
			}
			else if ((int)(input[i]) >= 47 && (int)(input[i]) <= 56) {
				tmp[2] += 1;
			}
			else if((int)(input[i])==32){
				tmp[3] += 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << tmp[i] << ' ';
		}
		cout << '\n';
		for (int i = 0; i < 4; i++) {
			tmp[i]=0;
		}
		input.clear();
	}


}