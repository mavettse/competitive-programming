/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
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

long long query(int esq, int dir){
    esq += pow2n; dir += pow2n;

    No esqNo = {}, dirNo = {};

    while(esq <= dir){
        if(esq % 2 == 1){
            esqNo = combinar(esqNo, st[esq]);
            esq++;
        }

        if(dir % 2 == 0){
            dirNo = combinar(st[dir], dirNo);
            dir--;
        }

        esq /= 2; dir /= 2; 
    }

    return combinar(esqNo, dirNo).maiorSubarray;
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

    int n, q; cin >> n >> q;
    pow2n = powDois(n);
    st.resize(2 * pow2n);

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        add(i, x);
    }

    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b; 
        a--; b--;
        cout << query(a,b) << '\n';
    }

    return 0;
}