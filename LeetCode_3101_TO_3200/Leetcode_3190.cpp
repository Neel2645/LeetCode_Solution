//* Question 3190 ---> Find Minimum Operations to Make All Elements Divisible by Three


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3 != 0) count++;
        }
        return count;
    }
};