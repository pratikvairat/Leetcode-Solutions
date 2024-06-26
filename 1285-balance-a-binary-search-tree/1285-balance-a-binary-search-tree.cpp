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
    vector<int> vec;
    TreeNode* balaceTree(int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid=start+(end-start)/2;
        cout<<mid<<" ";
        TreeNode* node=new TreeNode(vec[mid]);
        node->left=balaceTree(start,mid-1);
        node->right=balaceTree(mid+1,end);
        return node;
    }
    void InorderTraverse(TreeNode* root){
        if(root==NULL){
            return ;
        }
        InorderTraverse(root->left);
        vec.push_back(root->val);
        InorderTraverse(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        InorderTraverse(root);
        TreeNode* ans=balaceTree(0,vec.size()-1);
        return ans;
    }
};