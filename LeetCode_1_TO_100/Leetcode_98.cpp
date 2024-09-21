//* Question 98 ---> Validate Binary Search Tree

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 

class Solution {
public:
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);

        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1]) return false;
        }
        
        return true;
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 
//? here only Auxilury space is use not extra space will be used


class Solution {
public:
    void inorder(TreeNode* root,TreeNode* &prev,bool &flag)
    {
        if(root==NULL) return;
        inorder(root->left,prev,flag);
        if(prev)
        {
            if(prev->val>=root->val) 
            {
                flag = false;
                return;
            }
        }
        prev = root;
        inorder(root->right,prev,flag);
    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        TreeNode* prev = NULL;
        inorder(root,prev,flag);
        return flag;
    }
};



//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 
//? here only Auxilury space is use not extra space will be used


class Solution {
public:

    bool isValid(TreeNode* root,long mini,long maxi)
    {
        if(root==NULL) return true;

        if(root->val<=mini or root->val>=maxi) return false;

        return isValid(root->left,mini,root->val) and
               isValid(root->right,root->val,maxi);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};