//* Question - Max Consecutive Ones

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(1)  

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                count++;
               if(mx<count) mx = max(mx,count);
            }
            else count = 0;
        }
        return mx;
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int streak = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) streak = 0;
            else streak++;

            ans = max(ans,streak);
        }
        return ans;
    }
};


