/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int m;
vector<int> ordemDFS, reinos;
vector<bool> visitado; 

int operacao(char op, int x){
    if(op == '+'){
        return x;
    }

    return x+m;
}

int negacao(int x){
    if(x-m <= 0){
        return x+m;
    }

    return x-m;
}

void dfsBusca(int atual, const vector<vector<int>>& adj){
    visitado[atual] = 1;

    for(int filho : adj[atual]){
        if(!visitado[filho]){
            dfsBusca(filho, adj);
        }
    }

    ordemDFS.push_back(atual);
}

void dfs(int atual, const vector<vector<int>>& adj){
    visitado[atual] = 1;

    for(int filho : adj[atual]){
        if(visitado[filho]){
            continue;
        }

        reinos[filho] = reinos[atual];
        dfs(filho, adj);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n >> m;

    vector<vector<int>> adj(2*m+1, vector<int>()), adjRev(2*m+1, vector<int>());

    for(int i = 1; i <= n; ++i){
        char op1, op2; int a, b;
        cin >> op1 >> a >> op2 >> b;

        int ing1 = operacao(op1, a), ing2 = operacao(op2, b); 

        adj[negacao(ing1)].push_back(ing2); 
        adj[negacao(ing2)].push_back(ing1);
        
        adjRev[ing2].push_back(negacao(ing1));
        adjRev[ing1].push_back(negacao(ing2));
    }

    ordemDFS.reserve(2*m);
    visitado.assign(2*m+1, 0);

    for(int i = 1; i <= 2*m; ++i){
        if(!visitado[i]){
            dfsBusca(i, adj);
        }
    }

    int qtdReinos = 1;
    reinos.resize(2*m+1);
    visitado.assign(2*m+1, 0);

    for(auto it = ordemDFS.rbegin(); it != ordemDFS.rend(); ++it){
        if(!visitado[*it]){
            reinos[*it] = qtdReinos++;
            dfs(*it, adjRev);
        }
    }

    for(int i = 1; i <= m; ++i){
        if(reinos[i] == reinos[i+m]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for(int i = 1; i <= m; ++i){
        if(reinos[i] > reinos[i+m]){
            cout << "+ ";
        } else {
            cout << "- ";
        }
    }

    cout << '\n';

    return 0;
}