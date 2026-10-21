/* GIOVANNI ESTEVAM DOS SANTOS */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, f; cin >> n >> f;
    vector<int> cycles(n);

    for(int i = 0; i < n; ++i)
        cin >> cycles[i];

    ll minElement = *min_element(cycles.begin(), cycles.end()), up = f * minElement, down = minElement, ans = up;

    while(up >= down){
        ll mid = (up + down) / 2, coins = 0;

        for(auto cycle : cycles){
            coins += mid/cycle;

            if(coins >= f)
                break;
        }
        
        if(coins < f)
            down = mid+1;
        else {
            ans = mid;
            up = mid-1;
        }  
    }

    cout << ans << '\n';
    
    return 0;
}