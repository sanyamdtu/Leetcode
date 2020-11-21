/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
    void func(int n,TreeNode *root){
         n+=root->val;
        if(root->left==NULL&&root->right==NULL){
            
            sum+=n;
            return ;
        }
       
        if(root->left)
            func(10*n,root->left);
        if(root->right)
            func(10*n,root->right);
    }
    int sumNumbers(TreeNode* root) {
        if(root)
        func(0,root);
        return sum;
    }
};
