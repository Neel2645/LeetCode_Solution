//* Question  450 :- Delete Node in a BST

//! Method - 1
//? Time Complexity - O(height of tree)  
//? Space Complexity - O(1)  


class Solution {
public:
    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root)
    {
        while(root->right) root = root->right;

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        else if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(root)
        {
            if(key < root->val)
            {
                if(root->left!=NULL and root->left->val==key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else
            {
                if(root->right!=NULL and root->right->val==key)
                {
                    root->right = helper(root->right);
                    break;
                }    
                else root = root->right;
            }
        }
        return dummy;
    }
};

//! Method - 2
//? Time Complexity - O(height of tree)  
//? Space Complexity - O(1)  

class Solution {
public:
    TreeNode* predecessor(TreeNode* root)
    {
        if(root->left==NULL) return NULL;
        TreeNode* pred = root->left;
        while(pred->right) pred = pred->right;
        return pred;
    }
    TreeNode* successor(TreeNode* root)
    {
        if(root->right==NULL) return NULL;
        TreeNode* succ = root->right;
        while(succ->left) succ = succ->left;
        return succ;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key)
        {
            if(root->left==NULL and root->right==NULL) return NULL;

            else if(root->left==NULL or root->right==NULL)
            {
                if(root->left==NULL) return root->right;
                else return root->left;
            }
            else
            {
                // TreeNode* pred = predecessor(root);
                // root->val = pred->val;
                // root->left = deleteNode(root->left,pred->val);
                TreeNode* succ = successor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right,succ->val);
            }
        }
        else if(key < root->val) root->left = deleteNode(root->left,key);
        else root->right = deleteNode(root->right,key);
        return root;
    }
};