/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> nums(n);
    int x_max = 1;

    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        x_max = max(nums[i], x_max);
    }

    vector<int> divisores(x_max+1, 0);

    for(int i = 1; i <= x_max; ++i){
        int divisor = i;

        while(divisor <= x_max){
            divisores[divisor]++;
            divisor += i;
        }
    }

    for(const int& i : nums){
        cout << divisores[i] << '\n';
    }

    return 0;
}