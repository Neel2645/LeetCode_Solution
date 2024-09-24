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
};