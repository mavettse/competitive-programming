/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int comprimento, semaforos;
    cin >> comprimento >> semaforos;

    set<int> posSemaforos;
    posSemaforos.insert(0);
    posSemaforos.insert(comprimento);

    multiset<int> comprimentos;
    comprimentos.insert(comprimento);
    
    for(int i = 0; i < semaforos; ++i){
        int pos;
        cin >> pos;

        auto dir = posSemaforos.upper_bound(pos);
        auto esq = dir; 
        esq--;

        auto comp = comprimentos.find(*dir - *esq);
        comprimentos.erase(comp);

        posSemaforos.insert(pos);
        comprimentos.insert(pos - *esq);
        comprimentos.insert(*dir - pos);

        cout << *comprimentos.rbegin() << " ";
    }
    
    cout << "\n"; 
    
    return 0;
}