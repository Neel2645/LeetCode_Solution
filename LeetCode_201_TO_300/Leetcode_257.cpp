//* Question 257 -   Binary Tree Paths

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 

class Solution {
public:

    void paths(TreeNode* root,vector<string> &v,string s)
    {
        if(root==NULL) return;

        if(root->left==NULL and root->right==NULL)
        {
            s += to_string(root->val);
            v.push_back(s);
        }

        s += to_string(root->val);

        paths(root->left,v,s+"->");
        paths(root->right,v,s+"->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        paths(root,v,"");
        return v;
    }
};