/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int,int> nums;

    long long subValidos = 0;

    for(int dir = 0, esq = 0; dir < n; ++dir){
        int numAtual; 
        cin >> numAtual;
        
        auto pos = nums.find(numAtual);

        if(pos != nums.end() && pos->second >= esq){
            esq = pos->second + 1;
        }
        
        nums[numAtual] = dir;
        subValidos += dir - esq + 1;
    }

    cout << subValidos << "\n";
    
    return 0;
}