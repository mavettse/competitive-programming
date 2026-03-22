/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std; 

struct Edge{
    int a; int b; int c;
};

vector<Edge> edges;
int n, inicioCiclo = 0;
vector<int> pai;

void bellman_ford(){
    vector<long long> dist(n+1, 0);
    bool estabilizou;

    for(int i = 1; i < n; ++i){
        estabilizou = 1;

        for(const auto& [a, b, c] : edges){
            if(dist[a]+c < dist[b]){
                dist[b] = dist[a]+c;
                estabilizou = 0;
                pai[b] = a;
            }
        }

        if(estabilizou){
            return;
        }
    }

    for(const auto& [a, b, c] : edges){
        if(dist[a]+c < dist[b]){
            inicioCiclo = b;
            pai[b] = a;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int m; cin >> n >> m;

    edges.resize(m);
    pai.resize(n+1);

    for(int i = 0; i < m; ++i){
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }

    bellman_ford();

    if(inicioCiclo == 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for(int i = 0; i < n; ++i){
        inicioCiclo = pai[inicioCiclo];
    }
    
    vector<int> rota;
    rota.push_back(inicioCiclo);
    int noAux = pai[inicioCiclo];

    while(noAux != inicioCiclo){
        rota.push_back(noAux);
        noAux = pai[noAux];
    }

    rota.push_back(inicioCiclo);

    for(auto it = rota.rbegin(); it != rota.rend(); ++it){
        cout << *it << ' ';
    }

    cout << '\n';
    
    return 0;
}