//* Question - Same Tree

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n)  

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val != q->val) return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); 
    }
};



//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(m)
//? Where n = number of nodes
//? where m = max level of the tree  

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() and !q2.empty())
        {
            int val1 = q1.front()->val;
            int val2 = q2.front()->val;
            if(val1 != val2) return false;

            if(q1.front()->left and q2.front()->left)
            {
                q2.push(q2.front()->left);q1.push(q1.front()->left);
            } 
            else if(q1.front()->left or q2.front()->left) return false;
            
            if(q1.front()->right and q2.front()->right)
            {
                q2.push(q2.front()->right);
                q1.push(q1.front()->right);
            }
            else if(q1.front()->right or q2.front()->right) return false;
            q1.pop();
            q2.pop();
        }
        return true;
    }
};




//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(n)  


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL or q==NULL) return (p==q);

        return (p->val == q->val) && isSameTree(p->left,q->left) &&
                isSameTree(p->right,q->right);
    }
};





//! Method - 4
//? Time Complexity - O(n)  
//? Space Complexity - O(m)
//? Where n = number of nodes
//? where m = max level of the tree 


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() and !q2.empty())
        {
            TreeNode* temp1 = q1.front(); q1.pop();
            TreeNode* temp2 = q2.front(); q2.pop();

            if(temp1->val != temp2->val) return false;

            if(temp1->left and temp2->left)
            {
                q2.push(temp2->left);
                q1.push(temp1->left);
            } 
            else if(temp1->left!=NULL or temp2->left!=NULL) return false;
            
            if(temp1->right and temp2->right)
            {
                q2.push(temp2->right);
                q1.push(temp1->right);
            }
            else if(temp1->right!=NULL or temp2->right!=NULL) return false;
        
        }
        return true;
    }
};