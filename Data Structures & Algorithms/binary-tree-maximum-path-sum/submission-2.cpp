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
    int dfs(TreeNode* root, int& ma) {
        if (!root) return 0;
        int val = root->val;
        int lval = max(0, dfs(root->left, ma));
        int rval = max(0, dfs(root->right, ma));
        ma = max(ma, lval + rval + val);
        return val + max(lval, rval);
    }
    int maxPathSum(TreeNode* root) {
        int ma = root->val;
        int ans = dfs(root, ma);
        return ma;
    }
};
