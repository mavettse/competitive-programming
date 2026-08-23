/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    vector<pair<int,int>> nums;

    for(int i = 1; i <= n; ++i){
        int a; cin >> a;
        nums.push_back({a,i});
    } sort(nums.begin(), nums.end());

    for(int i = 0; i < n; ++i){
        int l = i+1, r = n-1, cur = nums[i].first;

        while(l < r){
            int sum = cur + nums[l].first + nums[r].first;

            if(sum == x){
                cout << nums[i].second << ' ' << nums[l].second << ' ' << nums[r].second << endl;
                return 0;
            }

            if(sum > x)
                r--;
            else
                l++;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}