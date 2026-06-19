/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        set<ListNode*> s;
        while (head) {
            ListNode* curr = head->next;
            if (s.contains(curr)) {
                return true;
            }
            s.insert(curr);
            head = head->next;
        }
        return false;
    }
};
