/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dist = 0, numL = 0, numR = 0, numU = 0;

        for (auto move : moves)
            if (move == 'L')
                numL++;
            else if (move == 'R')
                numR++;
            else 
                numU++;

        if(numL > numR)
            numU = -numU;

        dist = numR - numL + numU;

        return abs(dist);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    Solution sol;

    string moves;

    while(cin >> moves){
        cout << sol.furthestDistanceFromOrigin(moves) << '\n';
    }

    return 0;
}