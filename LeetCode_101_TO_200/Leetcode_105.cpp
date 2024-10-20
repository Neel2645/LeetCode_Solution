//* Question  105 :- Construct Binary Tree from Preorder and Inorder Traversal

//! Method - 1
//? Time Complexity - O(n^2)  
//? Space Complexity - O(n)  

class Solution {
public:
    int find(int x,vector<int>& in)
    {
        for(int i=0;i<in.size();i++) 
        {
            if(in[i]==x) return i;
        }
        return -1;
    }

    TreeNode* build(vector<int>& pre,int pl,int ph,vector<int>& in,int il,int ih)
    {
        if(pl>ph) return NULL;
        else if(il==ih) return new TreeNode(in[il]);

        TreeNode* root = new TreeNode(pre[pl]);
        int i = find(pre[pl],in);
        int no = i - il;
        root->left = build(pre,pl+1,pl+no,in,il,i-1);
        root->right = build(pre,pl+no+1,ph,in,i+1,ih);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return build(pre,0,pre.size()-1,in,0,in.size()-1);
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n)  

class Solution {
public:

    TreeNode* build(vector<int>& pre,int pl,int ph, 
    vector<int>& in,int il,int ih,unordered_map<int,int> &mp)
    {
        if(pl>ph) return NULL;
        else if(il==ih) return new TreeNode(in[il]);

        TreeNode* root = new TreeNode(pre[pl]);
        int i = mp[pre[pl]];
        int no = i - il;
        root->left = build(pre,pl+1,pl+no,in,il,i-1,mp);
        root->right = build(pre,pl+no+1,ph,in,i+1,ih,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int> mp;
        for(int i=0;i<in.size();i++) mp[in[i]] = i;
        return build(pre,0,pre.size()-1,in,0,in.size()-1,mp);
    }
};


//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(n)  

class Solution {
public:

    TreeNode* build(vector<int>& pre,vector<int>& in,int start,int end,int &idx,unordered_map<int,int> &mp)
    {
        if(start>end) return NULL;

        TreeNode* root = new TreeNode(pre[idx]);
        int i = mp[root->val];
        idx++;
        root->left = build(pre,in,start,i-1,idx,mp);
        root->right = build(pre,in,i+1,end,idx,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int> mp;
        for(int i=0;i<in.size();i++) mp[in[i]] = i;
        int idx = 0;
        return build(pre,in,0,in.size()-1,idx,mp);
    }
};