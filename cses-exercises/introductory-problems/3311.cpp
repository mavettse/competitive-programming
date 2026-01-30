/* GIOVANNI ESTEVAM DOS SANTOS*/

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    char grade[501][501] = {};
    char cores[] = {'A', 'B', 'C', 'D'};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char aux;
            cin >> aux;

            for(char c : cores){
                if((aux == c) || (i > 0 && grade[i-1][j] == c) || (j > 0 && grade[i][j-1] == c)){
                    continue;
                }

                grade[i][j] = c;
                break;
            }

            if(grade[i][j] == '\0'){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << grade[i][j];
        }

        cout << "\n";
    }

    return 0;
}