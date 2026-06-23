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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* ans = head;
        while (!lists.empty()) {
            lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
            int mi = INT_MAX;
            ListNode* fi = nullptr;
            for (int i = 0; i < lists.size(); i++) {
                ListNode* curr = lists[i];
                if (curr->val < mi) {
                    fi = curr;
                    mi = curr->val;
                }
            }
            head->next = fi;
            head = head->next;
            for (int i = 0; i < lists.size(); i++) {
                ListNode* curr = lists[i];
                if (curr->val == mi) {
                    lists[i] = lists[i]->next;
                    break;
                }
            }
        }
        return ans->next;
    }
};
