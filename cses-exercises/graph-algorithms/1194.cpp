/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
vector<vector<char>> mapa;

queue<pair<int,int>> filaMonstros;
vector<vector<int>> distMonstros, visitadoMonstros; 

queue<pair<int,int>> filaJogador;
vector<vector<int>> distJogador, visitadoJogador;
vector<vector<char>> direcoesJogador;
pair<int,int> fim = {-1, -1};

vector<int> dL   = { -1,   0,   1,   0}; // cima           baixo
vector<int> dC   = {  0,   1,   0,  -1}; //       direita         esquerda
vector<char> dir = {'U', 'R', 'D', 'L'}; // cima, direita, baixo, esquerda

void bfsMonstros(){
    while(!filaMonstros.empty()){
        pair<int,int> monstro1oFila = filaMonstros.front(); 
        filaMonstros.pop();
        int l = monstro1oFila.first, c = monstro1oFila.second;

        for(int i = 0; i < 4; ++i){
            int nL = l + dL[i], nC = c + dC[i];

            if(!visitadoMonstros[nL][nC] && mapa[nL][nC] != '#'){
                visitadoMonstros[nL][nC] = 1;
                distMonstros[nL][nC] = distMonstros[l][c] + 1;
                filaMonstros.push({nL,nC});
            }
        }
    }
}

void bfsJogador(){
    while(!filaJogador.empty()){
        pair<int,int> jogador1oFila = filaJogador.front();
        filaJogador.pop();
        int l = jogador1oFila.first, c = jogador1oFila.second;

        if(l == 1 || l == n || c == 1 || c == m){
            fim = {l, c};
            return;
        }

        for(int i = 0; i < 4; ++i){
            int nL = l + dL[i], nC = c + dC[i];

            if(!visitadoJogador[nL][nC] && mapa[nL][nC] == '.' && distJogador[l][c] + 1 < distMonstros[nL][nC]){
                visitadoJogador[nL][nC] = 1;
                distJogador[nL][nC] = distJogador[l][c] + 1;
                direcoesJogador[nL][nC] = dir[i];
                filaJogador.push({nL,nC});
            }
        }   
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    mapa.assign(n+2, vector<char>(m+2, '#'));
    
    distMonstros.assign(n+2, vector<int>(m+2, 1e9));
    visitadoMonstros.assign(n+2, vector<int>(m+2, 0));

    distJogador.assign(n+2, vector<int>(m+2, 0));
    visitadoJogador.assign(n+2, vector<int>(m+2, 0));
    direcoesJogador.assign(n+2, vector<char>(m+2, ' '));

    pair<int,int> inicio = {-1,-1};

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> mapa[i][j];

            if(mapa[i][j] == 'M'){
                filaMonstros.push({i,j});
                distMonstros[i][j] = 0;
                visitadoMonstros[i][j] = 1;
            } else if(mapa[i][j] == 'A'){
                inicio = {i,j};
                filaJogador.push({i,j});
                visitadoJogador[i][j] = 1;
            }
        }
    }

    bfsMonstros();
    bfsJogador();

    if(fim.first == -1){
        cout << "NO\n";
        return 0;
    }

    pair<int,int> atual = fim;
    string caminho;

    while(atual != inicio){
        int atualL = atual.first, atualC = atual.second;
        char dirAtual = direcoesJogador[atualL][atualC];
        caminho.push_back(dirAtual);

        switch(dirAtual){
            case 'U':
                atualL++;
                break;
            case 'R':
                atualC--;
                break;
            case 'D':
                atualL--;
                break;
            case 'L':
                atualC++;
                break;
        }

        atual = {atualL, atualC};
    }

    cout << "YES\n" << caminho.size() << "\n";

    for(auto c = caminho.rbegin(); c != caminho.rend(); ++c){
        cout << *c;
    }

    cout << "\n";
        
    return 0;
}