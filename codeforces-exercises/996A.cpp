#include <iostream>
using namespace std;

const int bill[] = {1,5,10,20,100};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int n, bills = 0; cin >> n;

	for(int i = 4; i >= 0; --i){
		bills += n/bill[i];
		n = n%bill[i];
	}

	cout << bills << '\n';

	return 0;
}
