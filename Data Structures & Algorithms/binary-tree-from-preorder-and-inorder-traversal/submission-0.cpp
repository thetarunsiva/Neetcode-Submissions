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
    unordered_map<int, int> mpp;
    int preIndex = 0;
    TreeNode* build(int L, int R, vector<int> preorder, vector<int> inorder) {
        if (L > R) return nullptr;
        int val = preorder[preIndex];
        TreeNode* root = new TreeNode(val);
        preIndex++;
        int mid = mpp[root->val];
        root->left = build(L, mid-1, preorder, inorder);
        root->right = build(mid+1, R, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(0, inorder.size()-1, preorder, inorder);
        return root;
    }
};
