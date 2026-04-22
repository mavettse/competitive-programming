/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N_MAX = 262144;

int v[N_MAX];
long long seg[2*N_MAX], lazy_add[2*N_MAX], lazy_set[2*N_MAX];
bool has_set[2*N_MAX];
int n;

ll junta(ll a, ll b){
    return a+b;
}

// soma x na posição p de tamanho tam
void poe_add(int p, ll x, int tam, bool prop = 1){
    seg[p] += x*tam;

    if(prop && p < n){ // se a posição p não for uma folha
        if(has_set[p]){
            lazy_set[p] += x;
        } else {
            lazy_add[p] += x;   
        }
    }
}

// substitui o valor na posição para x
void poe_set(int p, ll x, int tam, bool prop = 1){
    seg[p] = x*tam;

    if(prop && p < n){ // se a posição p não for uma folha
        lazy_set[p] = x;
        has_set[p] = 1;
        lazy_add[p] = 0; // o set destrói qualquer add pendente
    }
}

// atualiza todos os pais da folha p
void sobe(int p){
    for(int tam = 2; p /= 2; tam *= 2){
        seg[p] = junta(seg[2*p], seg[2*p+1]);

        if(has_set[p])
            seg[p] = lazy_set[p]*tam;
        else if(lazy_add[p])
            seg[p] += lazy_add[p]*tam;
    }
}

// propaga o caminho da raiz até a folha p
void prop(int p){
    int log_n = __builtin_ctz(n);
    int tam = n/2;

    for(int s = log_n; s; s--, tam /= 2){
        int i = p >> s;

        if(has_set[i]){
            poe_set(2*i, lazy_set[i], tam);
            poe_set(2*i+1, lazy_set[i], tam);
            has_set[i] = 0;
        } 

        if(lazy_add[i]){
            poe_add(2*i, lazy_add[i], tam);
            poe_add(2*i+1, lazy_add[i], tam);
            lazy_add[i] = 0;
        }
    }
}

// soma do range [a, b]
ll query(int a, int b){
    ll ret = 0; 

    for(prop(a+=n), prop(b+=n); a <= b; ++a/=2, --b/=2){
        if(a % 2 == 1)
            ret = junta(ret, seg[a]);
        if(b % 2 == 0)
            ret = junta(ret, seg[b]);
    }
    
    return ret;
}

// soma x em cada elemento do range [a,b] se o tipo for 1, ou troca cada elemento do range [a,b] para x se o tipo for 2
void update(int a, int b, int x, int tipo){
    prop(a += n); prop(b += n);

    for(int a2 = a, b2 = b, tam = 1; a2 <= b2; a2/=2, b2/=2, tam*=2){
        if(a2 % 2 == 1){
            if(tipo == 1){
                poe_add(a2++, x, tam);
            } else {
                poe_set(a2++, x, tam);
            }
        }

        if(b2 % 2 == 0){
            if(tipo == 1){
                poe_add(b2--, x, tam);
            } else {
                poe_set(b2--, x, tam);
            }
        }
    }

    sobe(a); sobe(b);
}

// constrói a segtree
void build(int n2, int* v){
    n = 1;
    
    while(n < n2)
        n *= 2;

    for(int i = 0; i < n; ++i)
        seg[n+i] = (i<n2) ? v[i] : 0;
    
    for(int i = n-1; i; --i)
        seg[i] = junta(seg[2*i], seg[2*i+1]);

    for(int i = 0; i < 2*n; ++i){
        lazy_add[i] = 0;
        lazy_set[i] = 0;
        has_set[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> n >> q;

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    build(n, v);

    for(int i = 0, op, a, b, x; i < q; ++i){
        cin >> op >> a >> b;

        switch(op){
            case 1:
                
            case 2:
                cin >> x;
                update(a-1,b-1,x,op);
                break;              

            case 3:
                cout << query(a-1,b-1) << '\n';
                break;
        }
    }

    return 0;
}