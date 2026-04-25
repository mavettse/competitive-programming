/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

map<string, int> usernames;
int n = 0;

int getID(string user){
    for(char& c : user)
        c = tolower(c);
    
    if(usernames.count(user)){
        return usernames[user];
    } 

    return (usernames[user] = n++);
}

int m;
vector<int> dist;
vector<pair<int,int>> arestas;

void bellmanford(){
    dist[0] = 1;

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j < m; ++j)
            if(dist[arestas[j].second] < dist[arestas[j].first] + 1){
                if(i == n)
                    return;

                dist[arestas[j].second] = dist[arestas[j].first] + 1;
            }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m; 
    arestas.assign(m, pair<int,int>());

    for(int i = 0; i < m; ++i){
        string nome1, nome2, lixo; 
        cin >> nome1 >> lixo >> nome2;
        int aresta1 = getID(nome2), aresta2 = getID(nome1);
        arestas[i] = {aresta1, aresta2};
    }

    dist.assign(n, 0); 
    bellmanford();

    int maiorDist = 0;

    for(int d : dist)
        maiorDist = max(maiorDist, d);

    cout << maiorDist << '\n';

    return 0;
}