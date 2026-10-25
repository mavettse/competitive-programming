/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dateToDays(const string& date){
        int month = (date[0] - '0') * 10 + (date[1] - '0');
        int day = (date[3] - '0') * 10 + (date[4] - '0');

        int yearDay = day;
        for(int i = 0; i < month-1; ++i) yearDay += monthDays[i];

        return yearDay;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string arrive = max(arriveAlice, arriveBob), leave = min(leaveAlice, leaveBob);

        if(leave < arrive) return 0;

        return dateToDays(leave) - dateToDays(arrive) + 1;
    }
};
