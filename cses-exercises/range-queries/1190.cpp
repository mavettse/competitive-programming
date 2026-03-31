/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct No{
    long long soma;
    long long prefixo;
    long long sufixo;
    long long maiorSubarray;
};

long long pow2n;
vector<No> st;

No combinar(const No& esq,const No& dir){
    No pai;

    pai.soma = esq.soma + dir.soma;
    pai.prefixo = max(esq.prefixo, esq.soma + dir.prefixo);
    pai.sufixo = max(esq.sufixo + dir.soma, dir.sufixo);
    pai.maiorSubarray = max({esq.maiorSubarray, dir.maiorSubarray, esq.sufixo + dir.prefixo});

    return pai;
}

void add(int k, int x){
    k += pow2n;

    st[k].soma = x;
    st[k].prefixo = max(0LL, (long long)x);
    st[k].sufixo = max(0LL, (long long)x);
    st[k].maiorSubarray = max(0LL, (long long)x);

    for(k /= 2; k >= 1; k /= 2){
        st[k] = combinar(st[2*k], st[2*k+1]);
    }
}

unsigned int powDois(unsigned int n){
    if(n == 0){
        return 1;
    }

    n--;

    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    n++;

    return n;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    pow2n = powDois(n);
    st.resize(2 * pow2n);

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        add(i, x);
    }

    for(int i = 0; i < m; ++i){
        int k, x; cin >> k >> x; 
        k--;
        add(k, x);
        cout << st[1].maiorSubarray << '\n';
    }

    return 0;
}