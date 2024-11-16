//* Question 628 :- Maximum Product of Three Numbers


//! Method - 1
//? Time Complexity =   O(n log n)
//? Space Complexity =   O(1)


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[n-1] * nums[n-2] * nums[n-3];
        int b = nums[0] * nums[1] * nums[n-1];
        return max(a,b);
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};