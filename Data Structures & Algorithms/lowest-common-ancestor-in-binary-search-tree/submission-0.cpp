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
    unordered_map<TreeNode*, int> mpp;
    bool dfs(TreeNode* root, TreeNode* target) {
        if (!root) return false;
        if (root == target) {
            mpp[root]++;
            return true;
        }
        if (dfs(root->left, target) || dfs(root->right, target)) {
            mpp[root]++;
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mpp.clear();
        dfs(root, p);
        dfs(root, q);
        TreeNode* ans;
        for (auto i : mpp) {
            if (i.second == 2) {
                ans = i.first;
            }
        }
        return ans;
    }
};
