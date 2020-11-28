                temp=temp->left;
            }
            temp->left=root->left;
            root=root->right;
            return root;
        }
    }
    TreeNode * func(TreeNode *root){
        if(root==NULL){
            return root;
        } 
        if(root->val>key){
            root->left=func(root->left);
            return root;
        }
        else if(root->val<key){
            root->right=func(root->right);
            return root;
        }
        else{
            return del(root);
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        this->key=key;
        return func(root);
    }
};
