//* Question 1464 --->  Maximum Product of Two Elements in an Array


//! Method - 1
//? Time Complexity - O(n logn)
//? Space Complexity - O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};