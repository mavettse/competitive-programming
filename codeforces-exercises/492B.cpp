/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, l; cin >> n >> l;
    vector<int> points(n);

    for(int& point : points)
        cin >> point;
    sort(points.begin(), points.end());

    int maxDif = 0;
    
    for(int i = 1; i < n; ++i)
    maxDif = max(maxDif, points[i]-points[i-1]);

    double d = maxDif/2.0;
        
    if(*points.begin() != 0)
        d = max(d, (double)*points.begin());

    if(*points.rbegin() != l)
        d = max(d, (double)l - *points.rbegin());

    cout << fixed << setprecision(10);
    cout << d << endl;
    
    return 0;
}