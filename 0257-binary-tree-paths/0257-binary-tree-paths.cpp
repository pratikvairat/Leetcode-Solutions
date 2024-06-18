/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* root, string path) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path + to_string(root->val));
        }
        if (root->left) {
            dfs(root->left, path + to_string(root->val) + "->");
        }
        if (root->right) {
            dfs(root->right, path + to_string(root->val) + "->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};