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
    TreeNode* lca(TreeNode* node,int p,int q){
        if(node==nullptr){
            return node;
        }
        TreeNode* leftSide=lca(node->left,p,q);
        TreeNode* rightSide=lca(node->right,p,q);

        if((leftSide && rightSide) ||(node->val==p||node->val==q)){
            return node;
        }
        return (leftSide==nullptr)?rightSide:leftSide;
    }
    string lcaToStart, lcaToEnd;
    void dfs(TreeNode* node,string& pathString,int p,int q){
        if(node==nullptr){
            return ;
        }
        if(node->val==p){
            lcaToStart=pathString;
        }
        if(node->val==q){
            lcaToEnd=pathString;
        }
        pathString.push_back('L');
        dfs(node->left,pathString,p,q);
        pathString.pop_back();

        pathString.push_back('R');
        dfs(node->right,pathString,p,q);
        pathString.pop_back();

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode=lca(root,startValue,destValue);
        string pathString = "";
        dfs(lcaNode,pathString,startValue,destValue);

        for(auto& i:lcaToStart){
            i='U';
        }
        return lcaToStart+lcaToEnd;
    }
};