/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    vector<int> nums;

    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1')
            nums.push_back(1);
        else if(s[i] == '2')
            nums.push_back(2);
        else if(s[i] == '3')
            nums.push_back(3);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i];

        if(i+1 < nums.size()){
            cout << '+';
        }
    }

    cout << '\n';

    return 0;
}