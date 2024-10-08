//* Question 287 --->  Find the Duplicate Number

//! Method - 1
//? Time Complexity - O(n)
//? Space Complexity - O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int &itr : nums)
        {
            if(mp[itr]==1) return itr;

            mp[itr]++;
        }
        return -1;
    }
}


//! Method - 2
//? Time Complexity - O(n logn)
//? Space Complexity - O(1)


class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        for(int i=0;i<(arr.size()-1);i++)
        {
            if(arr[i]==arr[i+1]) return arr[i];
        }
        return -1;
    }
};


//! Method - 3
//? Time  Complexity - O(n)
//? Space Complexity - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = nums[0];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};