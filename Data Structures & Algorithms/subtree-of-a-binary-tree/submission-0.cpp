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
    bool Sub = false;
    bool isSub = false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
    int dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root) return 0;
        isSub = isSameTree(root->left, subRoot);
        if (isSub) Sub = true;
        isSub = isSameTree(root->right, subRoot);
        if (isSub) Sub = true;
        return dfs(root->left, subRoot) + dfs(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        Sub = isSameTree(root, subRoot);
        if (Sub) return true;
        dfs(root, subRoot);
        return Sub;

    }
};
