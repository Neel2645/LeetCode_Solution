//* Question 700 - Search in a Binary Search Tree

//! Method - 1
//? Time Complexity - O(height) or O(log n)  
//? Space Complexity - O(height) or O(log n)


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL or root->val==val) return root;

        else if(val < root->val) return searchBST(root->left,val);

        else return searchBST(root->right,val);
    }
};


//! Method - 2
//? Time Complexity - O(height) or O(log n)  
//? Space Complexity - O(1)

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root)
        {
            if(root->val == val) return root;
            else if(val < root->val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};