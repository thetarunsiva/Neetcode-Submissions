/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummyPtr = new Node(0);
        unordered_map<Node*, Node*> mpp;
        Node* curr = head;
        while (curr) {
            Node* node = new Node(curr->val); // Creating new nodes..
            mpp[curr] = node;
            curr = curr->next;
        }
        Node* ans = dummyPtr;
        while (head) {
            Node* newNode = mpp[head]; // Using those new created nodes addresses..
            newNode->next = mpp[head->next];
            newNode->random = mpp[head->random];
            dummyPtr->next = newNode;
            dummyPtr = dummyPtr->next;
            head = head->next;
        }
        return ans->next;
    }
};
