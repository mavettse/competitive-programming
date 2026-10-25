/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:    
    int m, n;

    bool closed(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i > m-1 || j > n-1) return false; // está nas bordas = não é ilha fechada
        if(grid[i][j]) return true;
        grid[i][j] = 1;
        return closed(grid,i+1,j) & closed(grid,i-1,j) & closed(grid,i,j+1) & closed(grid,i,j-1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        int islands = 0;

        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) if(!grid[i][j]) islands += closed(grid, i, j);

        return islands;
    }
};
