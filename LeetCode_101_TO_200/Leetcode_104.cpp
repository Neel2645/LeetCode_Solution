//* Question 104 :- Maximum Depth of Binary Tree


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)

class Solution {
public:
    void helper(TreeNode* root,int &maxi,int curr)
    {
        if(root==NULL) return;
        maxi = max(maxi,curr);
        helper(root->left,maxi,curr+1);
        helper(root->right,maxi,curr+1);
    }

    int maxDepth(TreeNode* root) {
        int maxi = 0;
        helper(root,maxi,1);
        return maxi;
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)

class Solution {
public:
    int helper(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + max(helper(root->left),helper(root->right));
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};



//! Method - 3
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(q.size()!=0)
        {
            ans++;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* root = q.front();
                q.pop();
                if(root->left) q.push(root->left);  
                if(root->right) q.push(root->right);  
            }
        }
        return ans;
    }
};