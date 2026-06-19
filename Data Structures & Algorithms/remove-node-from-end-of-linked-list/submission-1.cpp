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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int ll = 0;
        while (ptr) {
            ptr = ptr->next;
            ll++;
        }
        int actual = ll - n;
        if (actual == 0) {
            // Deleting the first node is a special case, cuz prev is nullptr!
            head = head->next;
            return head;
        }
        ll = 0;
        ListNode* prev = nullptr;
        ListNode* head1 = head;
        while (head1) {
            if (ll == actual) {
                prev->next = head1->next;
                ll++;
                head1 = head1->next;
                continue;
            }
            prev = head1;
            head1 = head1->next;
            ll++;
        }
        cout << actual;
        return head;
    }
};
