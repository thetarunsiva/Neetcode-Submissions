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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        ListNode* curr = cur;
        int add = 0, carry = 0;
        while (l1 && l2) {
            int val = l1->val + l2-> val + carry;
            add = val%10;
            carry = val/10;
            ListNode* temp = new ListNode(add);
            curr->next = temp;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int val = l1->val + carry;
            add = val%10;
            carry = val/10;
            ListNode* temp = new ListNode(add);
            curr->next = temp;
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2) {
            int val = l2->val + carry;
            add = val%10;
            carry = val/10;
            ListNode* temp = new ListNode(add);
            curr->next = temp;
            curr = curr->next;
            l2 = l2->next;
        }
        if (carry) {
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
        }
        
        return cur->next;
    }
};
