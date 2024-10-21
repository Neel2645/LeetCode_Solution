//* Question  106 :- Construct Binary Tree from Postorder and Inorder Traversal

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

    TreeNode* build(vector<int>& post,int pl,int ph, 
    vector<int>& in,int il,int ih)
    {
        if(pl>ph) return NULL;
        else if(il==ih) return new TreeNode(in[il]);

        TreeNode* root = new TreeNode(post[ph]);
        int i = find(post[ph],in);
        int no = i - il;
        root->left = build(post,pl,pl+no-1,in,il,i-1);
        root->right = build(post,pl+no,ph-1,in,i+1,ih);
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return build(post,0,post.size()-1,in,0,in.size()-1);
    }
};