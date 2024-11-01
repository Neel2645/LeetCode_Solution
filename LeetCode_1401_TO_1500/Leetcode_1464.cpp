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



//! Method - 2
//? Time Complexity - O(n)
//? Space Complexity - O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[max2]<=nums[i])
            {
                max2 = i;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(max1<=nums[i] and i!=max2)
            {
                max1 = nums[i];
            }
        }
        return (max1-1)*(nums[max2]-1);
    }
};