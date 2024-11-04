//* Question 669 --->  Trim a Binary Search Tree


//! Method - 1
//? Time Complexity - O(n)
//? Space Complexity - O(n)


class Solution {
public:
    TreeNode* trim(TreeNode* root, int low, int high) {
        if(root==NULL) return root;

        TreeNode* leftNode  = trim(root->left,low,high);
        if(leftNode != root->left)
        {
            root->left = leftNode;
        }

        TreeNode* rightNode = trim(root->right,low,high);
        if(rightNode != root->right)
        {
            root->right = rightNode;
        }
        
        if(root->val>high or root->val<low)
        {
            return (root->left)?root->left : root->right; 
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }
};


//! Method - 2
//? Time Complexity - O(n)
//? Space Complexity - O(n)


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return root;

        else if(root->val >= low and root->val<=high)
        {
            root->left = trimBST(root->left,low,high);
            root->right = trimBST(root->right,low,high);
            return root;
        }

        else if(root->val > high)
        {
            return trimBST(root->left,low,high);
        }

        else if(root->val < low)
        {
            return trimBST(root->right,low,high);
        }
        return root;
    }
};