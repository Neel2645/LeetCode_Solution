//* Question 235 ---> Lowest Common Ancestor of a Binary Search Tree

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 

class Solution {
public:
    bool exits(TreeNode* root, TreeNode* key)
    {
        if(root==NULL) return false;
        else if(root->val==key->val) return true;

        return (exits(root->left,key) or exits(root->right,key));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(exits(root->left,p) and exits(root->left,q)) 
        return lowestCommonAncestor(root->left,p,q);

        else if(exits(root->right,p) and exits(root->right,q)) 
        return lowestCommonAncestor(root->right,p,q);

        return root;
    }
};

//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q) return root;

        TreeNode* leftN = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN = lowestCommonAncestor(root->right,p,q);

        if(leftN==NULL) return rightN;
        else if(rightN==NULL) return leftN;
        else return root;

    }
};

//! Method - 3
//? Time Complexity - O(log n) or O(Height of the tree)  
//? Space Complexity - O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q) return root;
        int x = root->val;
        if((x>p->val and x<q->val) or (x<p->val and x>q->val)) return root;

        else if(x>p->val and x>q->val) return lowestCommonAncestor(root->left,p,q);

        else return lowestCommonAncestor(root->right,p,q);
    }
};



//! Method - 4
//? Time Complexity - O(log n) or O(Height of the tree)  
//? Space Complexity - O(1)


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL) return root;
        
        int x = root->val;

        if(x>p->val and x>q->val) 
        return lowestCommonAncestor(root->left,p,q);

        else if(x<p->val and x<q->val) 
        return lowestCommonAncestor(root->right,p,q);

        return root;
    }
};