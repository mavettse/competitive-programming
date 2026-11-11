/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next;

        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};
