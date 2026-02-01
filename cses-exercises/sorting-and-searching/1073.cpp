/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> torres;
    torres.reserve(n);
    
    for(int i = 0; i < n; ++i){
        int cubo;
        cin >> cubo;

        auto posicao = upper_bound(torres.begin(), torres.end(), cubo);

        if(posicao == torres.end()){
            torres.push_back(cubo);
        } else {
            *posicao = cubo;
        }
    }

    cout << torres.size() << "\n";
    
    return 0;
}