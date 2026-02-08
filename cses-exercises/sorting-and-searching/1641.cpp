/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, alvo; cin >> n >> alvo;

    vector<pair<int,int>> nums;
    
    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        nums.push_back({num,i});
    }

    sort(nums.begin(), nums.end());

    int p1 = 0, p2 = 0, p3 = 0;

    for(int i = 0; i < n; ++i){
        int novoAlvo = alvo - nums[i].first;
        int esq = i+1, dir = n-1;

        while(esq < dir){
            int soma = nums[esq].first + nums[dir].first;

            if(soma > novoAlvo){
                dir--;
            } else if(soma < novoAlvo){
                esq++;
            } else {
                p1 = nums[i].second + 1;
                p2 = nums[esq].second + 1;
                p3 = nums[dir].second + 1;
                break;
            }
        }  

        if(p1 != 0){
            break;
        }
    }

    if(p1 != 0){
        cout << p1 << " " << p2 << " " << p3 << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}