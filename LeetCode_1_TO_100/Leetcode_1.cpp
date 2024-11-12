//* Question 1 --->  Two Sum


//! Method - 1
//? Time Complexity - O(n^2)
//? Space Complexity - O(1) 


class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                if(arr[i]+arr[j] == target) return {i,j};
            }
        }
        return {-1,-1};
    }
};


//! Method - 2
//? Time Complexity - O(n^2)
//? Space Complexity - O(1) 


class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j] == target) return {i,j};
            }
        }
        return {-1,-1};
    }
};


//! Method - 3
//? Time Complexity - O(n)
//? Space Complexity - O(n) 


class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<arr.size();i++)
        {
            int first = arr[i];
            int second = target - first;
            if(mp.find(second) != mp.end())
            {
                return {i,mp[second]};
            }
            mp[first] = i;
        }
        return {-1,-1};
    }
};
