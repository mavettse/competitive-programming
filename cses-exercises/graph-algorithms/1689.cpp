/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

// tamanho do tabulerio
const int N = 8;

int tabuleiro[N][N];

// movimentos que o cavalo pode fazer
const int dx[N] = {1, -1, 2,  2,  1, -1, -2, -2};
const int dy[N] = {2,  2, 1, -1, -2, -2,  1, -1};

// verifica se uma posição é válida (está dentro dos limites do tabuleiro e está vazia)
bool valid(int x, int y){
    return ((x >= 0 && y >= 0 && x < N && y < N) && (tabuleiro[x][y] == 0));
}

// retorna o grau das posições válidas (quantidade de posições válidas que um cavalo pode pular a partir da posição (x,y))
int getDegree(int x, int y){
    int qtd = 0;

    for(int i = 0; i < N; ++i){
        int nx = x + dx[i], ny = y + dy[i];

        if(valid(nx, ny))
            qtd++;
    }

    return qtd;
}

// retorna true se foi possível encontrar um novo movimento e false se não 
bool nextMove(int &x, int &y){

    // cria um número aleatório maior ou igual a 0 e menor que N 
    int initial = rand() % N;

    int minDegreeIdx = -1, nx, ny;

    // tenta todas as N posições adjacentes a (x,y) começando com uma casa aleatória e pega a casa vazia com o menor grau
    for(int count = 0, minDegree = N+1, c, i; count < N; ++count){
        i = (initial + count) % N;

        nx = x + dx[i]; ny = y + dy[i];

        if(valid(nx, ny) && (c = getDegree(nx, ny)) < minDegree){
            minDegree = c; 
            minDegreeIdx = i;
        }
    }

    // não encontrou uma casa vazia
    if(minDegreeIdx == -1)
        return false;

    nx = x + dx[minDegreeIdx]; ny = y + dy[minDegreeIdx];

    // o movimento da casa encontrada será o movimento da casa anterior + 1
    tabuleiro[nx][ny] = tabuleiro[x][y] + 1;
    // atualiza a casa atual
    x = nx; y = ny;

    return true;
}

// imprime o tabuleiro
void printBoard(){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            cout << tabuleiro[i][j] << ' ';
        cout << '\n';
    }
}

// utiliza a regra de warnsdorff: move o cavalo para a posição com a menor quantidade de posições válidas
// retorna false se não foi possível gerar todos os movimentos do cavalo
bool warnsdorff(int x, int y){
    // zera todas as casas da matriz 
    memset(tabuleiro, 0, sizeof(tabuleiro));

    // inicializa casa inicial com 1
    tabuleiro[x][y] = 1;

    int count = 1, xn = x, yn = y;

    // chama a função que dá o próximo passo e incrementa count
    while(nextMove(xn, yn)){
        count++;
    }

    // se a contadora tiver 64, todos as casas foram preenchidas
    if(count == 64){
        printBoard();
        return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    srand(time(NULL));

    int x, y; cin >> y >> x;

    while(!warnsdorff(x-1, y-1));

    return 0;
}