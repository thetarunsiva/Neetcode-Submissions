/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        vector<vector<int>> a;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int cc = q.size();
            vector<int> b;
            while (cc--) {
                TreeNode* curr = q.front();
                q.pop();
                b.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            a.push_back(b);
        }
        for (vector<int> i : a) {
            int right = i.back();
            ans.push_back(right);
        }
        return ans;
    }
};
