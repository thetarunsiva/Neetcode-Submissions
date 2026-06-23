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
            int mi = INT_MAX;
            int mi_index = 0;
            ListNode* fi = nullptr;
            for (int i = 0; i < lists.size(); i++) {
                ListNode* curr = lists[i];
                if (curr->val < mi) {
                    mi_index = i;
                    mi = curr->val;
                    fi = curr;
                }
            }
            head->next = fi;
            head = head->next;
            lists[mi_index] = lists[mi_index]->next;
            lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        }
        return ans->next;
    }
};
