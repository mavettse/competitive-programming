/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int di[] = {1, -1, 0,  0}, dj[] = {0,  0, 1, -1};
const char desc[] = {'D', 'U', 'R', 'L'};

int n, m;
vector<vector<bool>> lab;
pair<int,int> startPos, endPos;
vector<char> path;
vector<vector<char>> pai;
bool found = 0;

void backtracking(){
    found = 1; 
    pair<int,int> cur = endPos; 

    while(cur != startPos){
        auto& [i,j] = cur;
        char direction = pai[i][j];
        path.push_back(direction);

        switch(direction){
            case 'U': 
                i++;
                break;
            case 'D': 
                i--;
                break;
            case 'L': 
                j++;
                break;
            case 'R': 
                j--;
                break;
        }
    }
}

void bfs(){
    lab[startPos.first][startPos.second] = 0;
    queue<pair<int,int>> q; 
    q.push(startPos);

    while(!q.empty()){
        auto [ci, cj] = q.front(); 
        q.pop();
        
        
        for(int i = 0; i < 4; ++i){
            int ni = ci + di[i], nj = cj + dj[i];
            
            if(!lab[ni][nj])
            continue;
            
            lab[ni][nj] = 0;
            pai[ni][nj] = desc[i];
            q.emplace(ni, nj);

            if(pair<int,int>(ni, nj) == endPos){
                found = 1;
                backtracking();
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    lab.assign(n+2, vector<bool>(m+2, 0));
    pai.assign(n+2, vector<char>(m+2, ' '));

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            char c; cin >> c;
            
            if(c == '#')
                continue;
                
            if(c == 'A')
                startPos = {i,j};
            else if(c == 'B')
                endPos = {i,j};

            lab[i][j] = 1;            
        }

    bfs();

    if(found){
        cout << "YES\n" << path.size() << endl;
        for(auto it = path.rbegin(); it != path.rend(); it++)
            cout << *it;
        cout << endl;
    } else {
        cout << "NO\n";
    }

    return 0;
}