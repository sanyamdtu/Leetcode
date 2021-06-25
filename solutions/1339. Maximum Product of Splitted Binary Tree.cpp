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
typedef long long ll;
class Solution {
public:
    long long ans;
    ll sum;
    ll mod;
    void func(TreeNode * root){
        if(!root)
            return ;
        sum+=root->val;
        func(root->left);
        func(root->right);
    }
    ll fun(TreeNode * root){
        if(!root)
            return 0;
        ll l=fun(root->left);
        ll r=fun(root->right);
        ll a=l+r+root->val;
        ans=max(ans,max((sum-l)*l,(sum-r)*r));
        ans=max(ans,(sum-a)*a);
        return a;
    }
    int maxProduct(TreeNode* root) {
        sum=0;
        mod=1000000007;
        func(root);
        ll a=fun(root);
        return ans%mod;
    }
    
};
