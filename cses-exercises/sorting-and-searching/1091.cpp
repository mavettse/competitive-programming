/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <set>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int numTickets, numClientes;
    cin >> numTickets >> numClientes;

    multiset<int> precosTickets;

    for(int i = 0; i < numTickets; ++i){
        int aux;
        cin >> aux;        
        
        precosTickets.insert(aux);
    }    

    for(int i = 0; i < numClientes; ++i){
        int precoMax;
        cin >> precoMax;

        auto ptrMaior = precosTickets.upper_bound(precoMax);
        
        if(ptrMaior == precosTickets.begin()){
            cout << "-1\n";
        } else {
            ptrMaior--;
            cout << *ptrMaior << "\n";
            precosTickets.erase(ptrMaior);
        }
    }  

    return 0;
}