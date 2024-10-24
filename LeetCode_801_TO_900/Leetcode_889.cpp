//! Question  889 :- Construct Binary Tree from Preorder and Postorder Traversal

// using pre and post order we can't build unique BT
// But we build that unique full binary tree

//! Method - 1
//? Time Complexity - O(n^2)  
//? Space Complexity - O(n)  

class Solution {
public:
    int find(vector<int>& post,int key)
    {
        for(int i=0;i<post.size();i++)
        {
            if(post[i]==key) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& pre,int preStart,int preEnd,
    vector<int>& post,int postStart,int postEnd)
    {
        if(preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(pre[preStart]);
        if (preStart == preEnd) return root;  
        int idx = find(post,pre[preStart+1]);
        int n = idx - postStart + 1;

        root->left = build(pre,preStart+1,preStart+n,
                           post,postStart,idx);
        root->right = build(pre,preStart+n+1,preEnd,
                            post,idx+1,postEnd-1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, 
    vector<int>& post) {
        return build(pre,0,pre.size()-1,post,0,post.size()-1);
    }
};



//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n)  


class Solution {
public:
    TreeNode* build(vector<int>& pre,int preStart,int preEnd,
    vector<int>& post,int postStart,int postEnd, unordered_map<int,int>& mp)
    {
        if(preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(pre[preStart]);
        if (preStart == preEnd) return root;  
        int idx = mp[pre[preStart+1]];
        int n = idx - postStart + 1;

        root->left = build(pre,preStart+1,preStart+n,
                           post,postStart,idx,mp);
        root->right = build(pre,preStart+n+1,preEnd,
                            post,idx+1,postEnd-1,mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, 
    vector<int>& post) {
        unordered_map<int,int> mp;
        for(int i=0;i<post.size();i++)
        {
            mp[post[i]] = i;
        }
        return build(pre,0,pre.size()-1,post,0,post.size()-1,mp);
    }
};


//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(n)  

class Solution {
public:
    TreeNode* build(vector<int>& pre,int &preIndex,
    vector<int>& post,int postStart,int postEnd, unordered_map<int,int>& mp)
    {
        if((postStart > postEnd) or (preIndex>=post.size()))  return NULL;

        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (postStart == postEnd) return root;  
        int idx = mp[pre[preIndex]];

        root->left = build(pre,preIndex,
                           post,postStart,idx,mp);
        root->right = build(pre,preIndex,
                            post,idx+1,postEnd-1,mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, 
    vector<int>& post) {
        unordered_map<int,int> mp;
        for(int i=0;i<post.size();i++)
        {
            mp[post[i]] = i;
        }
        int preIndex = 0;
        return build(pre,preIndex,post,0,post.size()-1,mp);
    }
};