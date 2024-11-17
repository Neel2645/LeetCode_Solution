//* Question 2574 :- Left and Right Sum Differences

//! Method - 1
//? Time  Complexity =  O(n)
//? Space Complexity =  O(n)

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = nums;
        vector<int> right = nums;
        vector<int> ans(n,0);

        int leftSum = 0;
        int rightSum = 0;
        for(int i=0;i<n;i++)
        {
            left[i] = leftSum;
            leftSum += nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            right[i] = rightSum;
            rightSum += nums[i];
        }

        for(int i=0;i<n;i++)
        {
            ans[i] = abs(left[i]-right[i]);
        }
        return ans;
    }
};