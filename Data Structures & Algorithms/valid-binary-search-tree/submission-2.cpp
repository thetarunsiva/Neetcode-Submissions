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
    bool isBst = true;
    vector<int> a;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        a.push_back(root->val);
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prevNode = root;
        dfs(root);
        for (int i = 1; i < a.size(); i++) {
            if (a[i-1] >= a[i]) isBst = false;
        }
        return isBst;
    }
};
