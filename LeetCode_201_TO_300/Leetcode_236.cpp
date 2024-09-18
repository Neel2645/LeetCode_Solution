//* Question 236 ---> Lowest Common Ancestor of a Binary Tree

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 


class Solution {
public:
    bool exits(TreeNode* root, TreeNode* key)
    {
        if(root==NULL) return false;
        if(root->val==key->val) return true;
        return exits(root->left,key) or exits(root->right,key);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q) return root;
        else if(exits(root->left,p) and exits(root->right,q)) return root;
        else if(exits(root->left,q) and exits(root->right,p)) return root;
        else if(exits(root->left,p) and exits(root->left,q))
        return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 


class Solution {
public:
    bool exits(TreeNode* root, TreeNode* key)
    {
        if(root==NULL) return false;
        if(root->val==key->val) return true;
        return exits(root->left,key) or exits(root->right,key);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(exits(root->left,p) and exits(root->left,q))
        return lowestCommonAncestor(root->left,p,q);

        else if(exits(root->right,p) and exits(root->right,q))
        return lowestCommonAncestor(root->right,p,q);

        return root;
    }
};

//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
};

