class LRUCache {
public:
    class ListNode {
        public:
            int val;
            int key;
            ListNode* next;
            ListNode* prev;
            ListNode(int v, int k) : val(v), key(k), next(nullptr), prev(nullptr) {}
    };
    int n = 0;
    unordered_map<int, ListNode*> mpp;
    ListNode* head = new ListNode(0, 0);
    ListNode* tail = new ListNode(0, 0);
    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertFront(ListNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }

    void remove(ListNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    int get(int key) {
        if (mpp.count(key)) {
            remove(mpp[key]);
            insertFront(mpp[key]);
            return mpp[key]->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mpp.count(key)) {
            mpp[key]->val = value;
            remove(mpp[key]);
            insertFront(mpp[key]);
            return;
        }
        if (mpp.size() == n) {
            mpp.erase(tail->prev->key);
            remove(tail->prev);
        }
        ListNode* node = new ListNode(value, key);
        insertFront(node);
        mpp[key] = node;
    }
};
