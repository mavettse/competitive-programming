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

    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            long long novoAlvo = alvo - (nums[i].first + nums[j].first);

            if(novoAlvo < 2){
                continue;
            }

            int esq = j+1, dir = n-1;

            while(esq < dir){
                long long soma = nums[esq].first + nums[dir].first;

                if(soma > novoAlvo){
                    dir--;
                } else if(soma < novoAlvo){
                    esq++;
                } else {
                    p1 = nums[i].second + 1;
                    p2 = nums[j].second + 1;
                    p3 = nums[esq].second + 1;
                    p4 = nums[dir].second + 1;
                    break;
                }
            }  

            if(p1 != 0){
                break;
            }
        }

        if(p1 != 0){
            break;
        }
    }

    if(p1 != 0){
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}