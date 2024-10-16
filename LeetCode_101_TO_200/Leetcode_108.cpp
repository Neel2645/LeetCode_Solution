//* Question 108 ---> Convert Sorted Array to Binary Search Tree

//! Method - 1
//? Time  Complexity  - O(n)
//? Space Complexity  - O(n)


class Solution {
public:
    TreeNode* helper(vector<int>&arr,int low,int high)
    {
        if(low>high) return NULL;
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(arr,low,mid-1);
        root->right = helper(arr,mid+1,high);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1);
    }
};