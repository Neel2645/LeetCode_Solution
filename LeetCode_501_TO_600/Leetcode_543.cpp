//* Question 543 :- Diameter of Binary Tree


//! Method - 1
//? Time Complexity =   O(n^2)
//? Space Complexity =   O(n)

class Solution {
public:
    int levels(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }

    void diameter(TreeNode* root,int &maxi)
    {
        if(root==NULL) return;
        int lh = levels(root->left);
        int rh = levels(root->right);
        maxi = max(maxi,(lh+rh));

        diameter(root->left,maxi);
        diameter(root->right,maxi);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        diameter(root,maxi);
        return maxi;
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)


class Solution {
public:
    int helper(TreeNode* root,int &dia)
    {
        if(!root) return 0;
        int lh = helper(root->left,dia);
        int rh = helper(root->right,dia);
        dia = max(dia,(lh+rh));
        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        helper(root,dia);
        return dia;
    }
};