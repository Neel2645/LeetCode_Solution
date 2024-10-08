//! Question 35 -  Search Insert Position


//* Method - 1
//? Time Complexity - O(n)
//? Space Complexity - O(1)


class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            if(arr[i] >= x) return i;
        }
        return n;
    }
};


//* Method - 2
//? Time Complexity - O(log n)
//? Space Complexity - O(1)


class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        
        int n = arr.size();

        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;

    }
};

//* Method - 3
//? Time Complexity - O(log n)
//? Space Complexity - O(1)

class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        
        int ans =  lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        return ans;
    }
};