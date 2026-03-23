/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
using namespace std;

// INSERÇÃO DAS PBDS PARA USO DO ORDERED MULTISET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    ordered_multiset<pair<int,int>> funcionarios;
    vector<int> salarios(n); 

    for(int i = 0; i < n; ++i){
        int p; cin >> p; 
        funcionarios.insert({p,i});
        salarios[i] = p;
    }

    for(int i = 0; i < q; ++i){
        char op; cin >> op;

        if(op == '!'){
            int k, x; cin >> k >> x;
            k--;
            funcionarios.erase({salarios[k], k});
            funcionarios.insert({x, k});
            salarios[k] = x;
        } else if(op == '?'){
            int a, b; cin >> a >> b;
            int qtdB = funcionarios.order_of_key({b,1e9});
            int qtdA = funcionarios.order_of_key({a-1,1e9});
            cout << qtdB - qtdA << '\n';
        }
    }
    
    return 0;
}