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
        string user1, user2, lixo; 
        cin >> user1 >> lixo >> user2;
        int origem = getID(user2), destino = getID(user1);
        arestas[i] = {origem, destino};
    }

    dist.assign(n, 0); 
    bellmanford();

    int maiorDist = 0;

    for(int d : dist)
        maiorDist = max(maiorDist, d);

    cout << maiorDist << '\n';

    return 0;
}