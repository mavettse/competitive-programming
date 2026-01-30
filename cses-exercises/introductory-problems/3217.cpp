/* GIOVANNI ESTEVAM DOS SANTOS*/

#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;

    int dist[1001][1001];
    int dx[] = {1,  1, 2,  2, -1, -1, -2, -2};
    int dy[] = {2, -2, 1, -1,  2, -2,  1, -1};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dist[i][j] = -1;
        }
    }

    dist[0][0] = 0;
    queue<pair<int,int>> fila;
    fila.push({0,0});

    while(!fila.empty()){
        pair<int,int> aux = fila.front();
        int x = aux.first;
        int y = aux.second;
        fila.pop();

        int nx, ny;

        for(int i = 0; i < 8; ++i){
            nx = x + dx[i];
            ny = y + dy[i];

            if((nx >= 0 && nx < n) && (ny >= 0 && ny < n) && (dist[nx][ny] == -1)){
                dist[nx][ny] = dist[x][y] + 1;
                fila.push({nx,ny});
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}