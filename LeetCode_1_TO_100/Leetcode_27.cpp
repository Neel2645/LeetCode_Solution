//* Question 27 - Remove Element

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(1)


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};