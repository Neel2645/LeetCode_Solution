//* Question 704 :- Binary Search


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target) return i;
        }
        return -1;
    }
};


//! Method - 2
//? Time Complexity =   O(log n)
//? Space Complexity =   O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high)
        {
            // int mid = (low+high)/2;
            int mid = low + (high-low)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};