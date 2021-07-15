/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * t;
    int k;
    vector<int> ans;
    void down(TreeNode *root,int p=0){
        if(!root||p>k)
            return ;
        if(p==k)
            ans.push_back(root->val);
        down(root->left,p+1);
        down(root->right,p+1);          
    }
    int func(TreeNode * root){
        if(!root)
            return -1;
        if(root==t)
            return 1;
        int a= func(root->left);
        int b=func(root->right);
        int p=max(a,b);
        if(p==-1||p>k)
            return p;
        if(p==k)
            ans.push_back(root->val);
        if(a==p){
            down(root->right,p+1);
        }
        else{
            down(root->left,p+1);
        }
        return p+1;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int K) {
        ans.clear();
        t=tar;
        k=K;
        down(tar,0);
        func(root);
        return ans;
    }
};
