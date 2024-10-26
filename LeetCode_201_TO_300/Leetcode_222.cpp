//* Question 222 --->  Count Complete Tree Nodes


//! Method - 1
//? Time Complexity - O(n)
//? Space Complexity - O(H) --- height of the tree 


class Solution {
public:
    void inorder(TreeNode* root,int &cnt)
    {
        if(root==NULL) return;
        
        inorder(root->left,cnt);
        cnt++;
        inorder(root->right,cnt);
    }

    int countNodes(TreeNode* root) {
        int cnt = 0;
        inorder(root,cnt);
        return cnt;
    }
};

//! Method - 2
//? Time Complexity - O((log n)^2)
//? Space Complexity - O(log n)


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int lh = heightLeftTree(root);
        int rh = heightRightTree(root);

        if(lh==rh) return (1<<lh) - 1; // pow(2,lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int heightLeftTree(TreeNode* root)
    {
        int cnt = 0;
        while(root)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }

    int heightRightTree(TreeNode* root)
    {
        int cnt = 0;
        while(root)
        {
            cnt++;
            root = root->right;
        }
        return cnt;
    }
};