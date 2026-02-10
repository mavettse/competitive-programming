/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <stack>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    stack<pair<int,int>> nums;

    for(int i = 1; i <= n; ++i){
        int num; cin >> num;

        while(!nums.empty()){
            if(nums.top().first >= num){
                nums.pop();
            } else {
                cout << nums.top().second << " "; 
                break;
            }
        }

        if(nums.empty()){
            cout << "0 ";
        }
        
        nums.push({num,i});
    }

    cout << "\n";
    
    return 0;
}