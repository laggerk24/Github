
// Definition for a Node.
#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* cloneGraphUtil(Node* node, map<Node*,Node*> &mpp){
    if(node == NULL) return node;
    Node* newNode = new Node(node->val);
    mpp[node] = newNode;
    for(auto neighbor:node->neighbors){
        if(mpp.find(neighbor) != mpp.end())
            newNode->neighbors.push_back(mpp[neighbor]);
        else
            newNode->neighbors.push_back(cloneGraphUtil(neighbor,mpp));
    }
    return newNode;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mpp;
        return cloneGraphUtil(node,mpp);
    }
};
int main(){
  cout<<"hello world";
}
 