/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    map<int, int> nums; // nums[key] = value

    for(int i = 1; i <= n; ++i){
        int num; cin >> num;
        int target = x - num;

        auto it = nums.find(target);

        if(it != nums.end()){
            cout << it->second << ' ' << i << '\n';
            return 0;
        } 

        nums[num] = i;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}