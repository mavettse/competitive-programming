/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
using namespace std;

// INCLUSÃO PARA USO DE ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    ordered_set nums;
    for(int i = 1; i <= n; ++i){
        nums.insert(i);
    }

    int pos = 0;

    while(!nums.empty()){
        pos = (pos + k) % nums.size();

        auto remover = nums.find_by_order(pos);
        cout << *remover << " ";
        nums.erase(remover);
    }

    cout << "\n";

    return 0;
}