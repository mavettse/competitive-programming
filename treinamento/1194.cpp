/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005, INF = 1e9+7, di[] = {1, -1,  0, 0}, dj[] = {0,  0, -1, 1};
const char desc[] = {'D', 'U', 'L', 'R'};

bool grid[MAX][MAX]; 
int monSteps[MAX][MAX], humSteps[MAX][MAX];
char parent[MAX][MAX];
bool possible = 0;
int n, m;
vector<char> ans;

void bfsMonsters(vector<pair<int,int>>& mPos){
    queue<pair<int,int>> q; 

    for(auto pos : mPos){
        q.emplace(pos);
        monSteps[pos.first][pos.second] = 0;
    }

    while(!q.empty()){
        auto [iPos, jPos] = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i){
            int ni = iPos + di[i], nj = jPos + dj[i];

            if(!grid[ni][nj] || monSteps[ni][nj] <= monSteps[iPos][jPos] + 1)
                continue;

            monSteps[ni][nj] = monSteps[iPos][jPos] + 1;
            q.emplace(ni,nj);
        }
    }
}

void backtracking(pair<int,int> startPos, pair<int,int> endPos){
    auto& [iE, jE] = endPos;

    while(startPos != endPos){
        switch(parent[iE][jE]){
            case 'D':
                iE--;
                ans.push_back('D');
                break;
            case 'U':
                iE++;
                ans.push_back('U');
                break;
            case 'L': 
                jE++;
                ans.push_back('L');
                break;
            case 'R':
                jE--;
                ans.push_back('R');
                break;
            default:
                return;
        }
    }
}

void bfs(pair<int,int> startPos){
    queue<pair<int,int>> q; 
    q.emplace(startPos);
    humSteps[startPos.first][startPos.second] = 0;

    while(!q.empty()){
        auto [iPos, jPos] = q.front();
        q.pop();

        if(iPos == 1 || iPos == n || jPos == 1 || jPos == m){
            possible = 1;
            backtracking(startPos, {iPos, jPos});
            return;
        }

        for(int i = 0; i < 4; ++i){
            int ni = iPos + di[i], nj = jPos + dj[i];

            if(!grid[ni][nj] || monSteps[ni][nj] <= humSteps[iPos][jPos] + 1 || humSteps[ni][nj] <= humSteps[iPos][jPos] + 1)
                continue;

            humSteps[ni][nj] = humSteps[iPos][jPos] + 1;
            parent[ni][nj] = desc[i];
            q.emplace(ni,nj);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    memset(grid, 0, sizeof(grid));
    memset(monSteps, INF, sizeof(monSteps));
    memset(parent, ' ', sizeof(parent));
    memset(humSteps, INF, sizeof(humSteps));

    cin >> n >> m;

    vector<pair<int,int>> mPos;
    pair<int,int> startPos; 

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c; cin >> c; 

            if(c == '#')
                continue;

            grid[i][j] = 1;

            if(c == 'M')
                mPos.emplace_back(i,j);
            else if(c == 'A')
                startPos = {i,j};
        }
    }

    bfsMonsters(mPos);
    bfs(startPos);

    if(!possible){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n" << ans.size() << '\n';
    for(auto it = ans.rbegin(); it != ans.rend(); ++it){
        cout << *it;
    } cout << endl;
    
    return 0;
}