/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool dfs(vector<vector<char>>& grid, int m, int n, vector<vector<bool>>& visited, int ci, int cj, int pi, int pj){
        int di[] = {0,  0, 1, -1};
        int dj[] = {1, -1, 0,  0};

        visited[ci][cj] = 1;

        for(int i = 0; i < 4; ++i){
            int ni = ci + di[i], nj = cj + dj[i]; 

            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == grid[ci][cj]){
                if(!visited[ni][nj]){
                    if(dfs(grid, m, n, visited, ni, nj, ci, cj))
                        return true;
                } else if(pi != ni || pj != nj){
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(!visited[i][j] && dfs(grid, m, n, visited, i, j, -1, -1))
                    return true;

        return false;
    }
};