/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int,int> playlist;
    playlist.reserve(n);

    int valorMax = 0;    
    int inicio = 0; 
    int fim = 0;
    
    for(int i = 0; i < n; ++i){
        int faixa;
        cin >> faixa;

        auto resultado = playlist.find(faixa);

        if(resultado != playlist.end() && resultado->second >= inicio){
            inicio = resultado->second + 1;
        }

        playlist[faixa] = i;
        fim = i;
        valorMax = max(valorMax, fim-inicio+1);
    }

    cout << valorMax << "\n";
    
    return 0;
}