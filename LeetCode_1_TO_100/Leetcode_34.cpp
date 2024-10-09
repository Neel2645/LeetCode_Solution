//* Question 34 - Find First and Last Position of Element in Sorted Array

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target)
            {
                if(first==-1) first = i;
                last = i;
            }
        }
        return  {first,last};
    }
};


//! Method - 2
//? Time Complexity - O(log n)  
//? Space Complexity - O(1)


class Solution {
public:

    int lowerBound(vector<int> &arr,int x)
    {
        int ans = arr.size();
        int low = 0;
        int high = arr.size()-1;

        while( low <= high )
        {
            int mid = low + (high-low)/2;
            if(arr[mid]>=x)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    int upperBound(vector<int> &arr,int x)
    {
        int ans = arr.size();
        int low = 0;
        int high = arr.size()-1;

        while(low <= high)
        {
            int mid  = low + (high - low)/2;

            if(arr[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,target);
        int up = upperBound(nums,target);

        if(lb==nums.size() or nums[lb]!=target) return {-1,-1};
        
        return {lb,up-1};
    }
};


//! Method - 3
//? Time Complexity - O(log n)  
//? Space Complexity - O(1)


class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int up = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

        if(lb==nums.size() or nums[lb]!=target) return {-1,-1};
        
        return {lb,up-1};
    }
};