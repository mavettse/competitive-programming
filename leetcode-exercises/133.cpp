/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*> copies; // copies[original] = copy
        copies[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(Node* neighbor : cur->neighbors){
                if(copies.find(neighbor) == copies.end()){
                    copies[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copies[node];
    }
};
