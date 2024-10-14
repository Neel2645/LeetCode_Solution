//* Question 81 ---> Search in Rotated Sorted Array II

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 


class Solution {
public:
    bool search(vector<int>& arr, int x) {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == x) return true;
        }
        return false;
    }
};

//! Method - 2   
//? Time Complexity - O(log n)  
//? Space Complexity - O(1) 

//! but in worst case it is O(N) time complexity
//! Example 1 1 1 1 1 1 1 2 1 1 1 1 1 1      target = 2
  
class Solution {
public:
    bool search(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size()-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(arr[mid] == x) return true;

            else if(arr[low]==arr[mid] and arr[mid]==arr[high])
            {
                low++;
                high--;
            }

            else if(arr[mid]<=arr[high])
            {
                if(arr[mid]<=x and x<=arr[high]) low = mid + 1;
                else high = mid - 1;
            }

            else
            {
                if(arr[low]<=x and x<=arr[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return false;
    }
};