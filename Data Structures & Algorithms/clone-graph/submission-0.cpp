/*
// Definition for a Node.
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
*/

class Solution {
public:
    unordered_map<Node*, Node*> mpp;
    Node* dfs(Node* curr) {
        if (mpp.contains(curr)) {
            return mpp[curr];
        }
        Node* node = new Node(curr->val);
        mpp[curr] = node;
        for (Node* neighbor : curr->neighbors) {
            Node* neigh = dfs(neighbor);
            node->neighbors.push_back(neigh);
        }
        return node;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* start = dfs(node);
        return start;
    }
};
