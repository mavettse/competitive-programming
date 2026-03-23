/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
using namespace std;

// INSERÇÃO DAS PBDS PARA USO DO ORDERED MULTISET COM A FUNÇÃO FIND BY ORDER
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ordered_multiset<pair<int,int>> lista;

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        lista.insert({i,x});
    }

    for(int i = 0; i < n; ++i){
        int p; cin >> p;
        auto elemento = lista.find_by_order(p-1);
        cout << elemento->second << ' ';
        lista.erase(elemento);
    }

    cout << '\n';
    
    return 0;
}