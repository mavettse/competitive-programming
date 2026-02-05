/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> circulo;

    for(int i = 1; i <= n; ++i){
        circulo.push(i);
    }

    int remover = 0;

    while(!circulo.empty()){
        if(remover){
            cout << circulo.front() << " ";
        } else {
            circulo.push(circulo.front());
        }

        circulo.pop();
        remover = !remover;
    }

    cout << "\n";

    return 0;
}