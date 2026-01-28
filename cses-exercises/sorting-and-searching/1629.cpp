/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int numFilmes;
    cin >> numFilmes;

    pair<int,int> filme;

    vector<pair<int,int>> horarios;
    horarios.reserve(numFilmes);

    for(int i = 0; i < numFilmes; ++i){
        int a, b;
        cin >> a >> b;

        filme.first = b; // {fim, início}
        filme.second = a;

        horarios.push_back(filme);
    }

    sort(horarios.begin(), horarios.end());

    int filmesAssistidos = 1, ultimaHrF = horarios[0].first;  

    for(int i = 1; i < numFilmes; ++i){
        if(horarios[i].second >= ultimaHrF){
            filmesAssistidos++;
            ultimaHrF = horarios[i].first;
        }
    }

    cout << filmesAssistidos << "\n";
    
    return 0;
}