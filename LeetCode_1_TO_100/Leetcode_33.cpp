//* Question 33 - Search in Rotated Sorted Array

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target) return i;
        }
        return -1;
    }
};
