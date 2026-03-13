/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n);
    vector<long long> prefixSum(n+1, 0);

    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        arr[i] = num;
        prefixSum[i+1] = num + prefixSum[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n));

    for(int i = 0; i < n; ++i){
        dp[i][i] = arr[i];
    }

    for(int tamIntervalo = 2; tamIntervalo <= n; ++tamIntervalo){
        int esq = 0, dir = tamIntervalo - 1;

        while(dir <= n-1){
            long long somaIntervalo = prefixSum[dir+1] - prefixSum[esq];

            dp[esq][dir] = somaIntervalo - min(dp[esq+1][dir], dp[esq][dir-1]);
            esq++; dir++;
        }
    }

    cout << dp[0][n-1] << "\n";

    return 0;
}