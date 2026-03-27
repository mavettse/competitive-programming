/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int n; 
vector<vector<int>> adj;
vector<int> tamSubTree;
vector<int> pai;

void dfs(const int& noAtual, const int& noPai){
    tamSubTree[noAtual]++;
    pai[noAtual] = noPai;

    for(auto const& noFilho : adj[noAtual]){
        if(noFilho == noPai){
            continue;
        }

        dfs(noFilho, noAtual);
        tamSubTree[noAtual] += tamSubTree[noFilho];
    }   
}

bool ehCentroide(const int& noAtual, const int& noPai){
    int maxSubTree = n/2;

    if(n-tamSubTree[noAtual] > maxSubTree){
        return false;
    }

    for(auto const& noFilho : adj[noAtual]){
        if(noFilho == noPai){
            continue;
        }

        if(tamSubTree[noFilho] > maxSubTree){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    adj.assign(n+1, vector<int>());
    tamSubTree.assign(n+1, 0); 
    pai.assign(n+1, 0); 

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i = 1; i <= n; ++i){
        if(ehCentroide(i, pai[i])){
            cout << i << '\n';
            return 0;
        }
    }
    
    return 0;
}