//* Question 33 - Search in Rotated Sorted Array

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target) return i;
        }
        return -1;
    }
};


//! Method - 2
//? Time Complexity - O(log n)  
//? Space Complexity - O(1) 


class Solution {
public:
    int search(vector<int>& arr, int k) {
        int s = 0;
        int e = arr.size()-1;

        while( s <= e )
        {
            int mid = (s+e)/2;

            if( arr[mid] == k ) return mid;

            if(arr[s] <= arr[mid])
            {
                if(arr[s]<=k and k<=arr[mid]) e = mid - 1;
                else s = mid + 1;
            }
            else
            {
                if(arr[mid]<=k and k<=arr[e]) s = mid + 1;
                else e = mid - 1;
            }
        }
        return -1;
    }
};



//! Method - 3
//? Time Complexity - O(log n)  
//? Space Complexity - O(1)


class Solution {
public:
    int findMinimum(vector<int>& arr)
    {
        int s = 0;
        int e = arr.size()-1;
    
        while( s < e )
        {
            int mid = (s+e)/2;

            if(arr[mid] < arr[e]) e = mid;
            else s = mid + 1;
        }
        return s;
    }
    
    int binarySearch(vector<int> &arr,int k,int s,int e)
    {
        while( s <= e )
        {
            int mid = (s+e)/2;

            if(arr[mid]==k) return mid;
            else if(arr[mid]<k) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& arr, int k) {
        int n = arr.size()-1;
        int pivot = findMinimum(arr);

        if(arr[pivot]<=k and k<=arr[n])
        return binarySearch(arr,k,pivot,n);
    
        else
        return binarySearch(arr,k,0,pivot-1);
    }
};