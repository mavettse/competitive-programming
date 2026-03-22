/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MODULO = 1e9+7;
const int MAX_NOS = 1e6+1;

int trie[MAX_NOS][26];
bool fimPalavra[MAX_NOS];
int totalNos = 1;

void inserir(string& palavra){
    int localAtual = 0;

    for(const char& c : palavra){
        int idx = c - 'a';
        
        if(trie[localAtual][idx] == 0){
            trie[localAtual][idx] = totalNos++;
        }
        
        localAtual = trie[localAtual][idx];
    }

    fimPalavra[localAtual] = 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;

    for(int i = 0; i < k; ++i){
        string palavra;
        cin >> palavra;
        inserir(palavra);
    }

    vector<int> dp(n+1, 0);
    dp[n] = 1;

    for(int i = n-1; i >= 0; --i){
        int localAtual = 0;

        for(int j = i; j < n; ++j){
            int idx = s[j] - 'a';
            localAtual = trie[localAtual][idx];

            if(localAtual == 0){
                break;
            }

            if(fimPalavra[localAtual]){
                dp[i] = (dp[i] + dp[j+1]) % MODULO;
            }
        }
    }

    cout << dp[0] << '\n';
    
    return 0;
}