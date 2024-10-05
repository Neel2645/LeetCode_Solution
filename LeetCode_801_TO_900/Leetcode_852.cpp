//* Question 852 :- Peak Index in a Mountain Array


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for(int i=1;i<=arr.size()-2;i++)
        {
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]) return i;
        }
        return -1;
    }
};


//! Method - 2
//? Time Complexity =   O(log n)
//? Space Complexity =   O(1)


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1;
        int high = arr.size()-2;

        while( low <= high )
        {
            int mid = low + (high-low)/2;

            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])
            return mid;

            else if(arr[mid]>arr[mid-1]) low = mid + 1;

            else high = mid - 1;
        }
        return -1;
    }
};