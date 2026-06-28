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

class Codec {
public:
    string s = "";
    void dfs(TreeNode* root) {
        if (!root) {
            s += "null,";
            return;
        }
        int val = root->val;
        string curr = to_string(val);
        s += curr+",";
        dfs(root->left);
        dfs(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs(root);
        cout << s << endl;
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* dfs_build(vector<string> strings, int& idx) {
        if (strings[idx] == "null") {
            idx++;
            return nullptr;
        }
        int val = stoi(strings[idx]);
        idx++;
        TreeNode* curr = new TreeNode(val);
        curr->left = dfs_build(strings, idx);
        curr->right = dfs_build(strings, idx);
        return curr;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string sub;
        vector<string> strings;
        while (getline(ss, sub, ',')) {
            strings.push_back(sub);
        }
        int idx = 0;
        TreeNode* root = dfs_build(strings, idx);
        return root;
    }
};
