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
    TreeNode* prev = nullptr;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (!prev) {
            prev = root;
        }
        else {
            if (prev->val >= root->val) {
                isBst = false;
            }
            prev = root;
        }
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return isBst;
    }
};
