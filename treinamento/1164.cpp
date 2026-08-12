/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<pair<int,int>> arrivals(n), departures(n); // {time, index}
    
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        arrivals[i] = {a,i};
        departures[i] = {b,i};
    }
    
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    
    vector<int> rooms(n, -1), avaiableRooms;
    int minRooms = 0;
    int arrPtr = 0, depPtr = 0;

    while(arrPtr < n){
        auto [arrTime, arrIdx] = arrivals[arrPtr];
        auto [depTime, depIdx] = departures[depPtr];

        while(depTime < arrTime && depIdx != arrIdx){
            avaiableRooms.push_back(rooms[depIdx]);
            tie(depTime, depIdx) = departures[++depPtr];
        }

        int roomNum;
        
        if(!avaiableRooms.empty()){
            roomNum = avaiableRooms.back();
            avaiableRooms.pop_back();
        } else {
            roomNum = ++minRooms;
        }
        
        rooms[arrIdx] = roomNum;
        arrPtr++;
    }

    cout << minRooms << '\n';
    for(int num : rooms)
        cout << num << ' ';
    cout << '\n';

    return 0;
}