/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> pesos(n);

    for(int i = 0; i < n; ++i){
        cin >> pesos[i];
    }

    vector<pair<int, int>> dp(1<<n, pair<int,int>({n+1,0})); // {viagens, pesoUltima}
    dp[0] = {1,0};

    for(int mask = 0; mask < (1<<n); ++mask){

        for(int i = 0; i < n; ++i){
            if((mask & (1<<i)) == 0){ // se a pessoa i ainda nao entrou, seu bit é 0
                int viagens = dp[mask].first;
                int pesoAtual = dp[mask].second;
                int p = pesos[i];

                int novoPeso, novasViagens;

                if(pesoAtual + p > x){ // peso maximo atingido; o elevador sobe e volta com o peso da pessoa i
                    novasViagens = viagens + 1;
                    novoPeso = p;
                } else { // a pessoa i pode ir nessa viagem 
                    novasViagens = viagens;
                    novoPeso = pesoAtual + p;
                }

                int nextMask = mask | (1<<i); // acende o bit da pessoa i
                dp[nextMask] = min(dp[nextMask], {novasViagens, novoPeso});
            }
        }
    }

    cout << dp[(1<<n) - 1].first << "\n";

    return 0;
}