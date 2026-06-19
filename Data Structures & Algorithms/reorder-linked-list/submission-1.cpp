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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* tail = head;
        ListNode* prev = nullptr;
        int ll = 1;
        while (tail->next) {
            tail = tail->next;
            ll++;
        }
        if (ll < 3) return;
        tail = head;
        int mid = ll/2;
        int n = 0;
        while (tail->next) {
            if (n > mid) break;
            prev = tail;
            tail = tail->next;
            n++;
        }
        prev->next = nullptr;
        
        // Reversing the second half..
        ListNode* past = nullptr;
        ListNode* present = tail;
        while (present) {
            ListNode* future = present->next;
            present->next = past;
            past = present;
            present = future;
        }
        // Past now points to the first element in the reversed half..
        // Head points to the first element in the first half..
        while (past) {
            ListNode* t2 = past->next;
            ListNode* t1 = head->next;
            head->next = past;
            past->next = t1;
            head = t1;
            past = t2;
        }

    }
};
