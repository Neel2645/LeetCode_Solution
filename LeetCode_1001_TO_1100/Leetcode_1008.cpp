//* Question  1008 :- Construct Binary Search Tree from Preorder Traversal

//! Method - 1
//? Time Complexity - O(n^2)  
//? Space Complexity - O(n)  

class Solution {
public:
    TreeNode* insert(TreeNode* root,int val)
    {
        if(root==NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        else if(val < root->val)
        {
            root->left = insert(root->left,val);
        }
        else
        {
            root->right = insert(root->right,val);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);

        for(int i=1;i<pre.size();i++)
        {
            insert(root,pre[i]);
        }
        return root;
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n)


class Solution {
public:
    TreeNode* helper(vector<int>& arr,int &i,int bound)
    {
        if(i==arr.size() or arr[i]>bound) return NULL;
        TreeNode* root = new TreeNode(arr[i++]);
        root->left = helper(arr,i,root->val);
        root->right = helper(arr,i,bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i = 0;
        return helper(arr,i,INT_MAX);
    }

};