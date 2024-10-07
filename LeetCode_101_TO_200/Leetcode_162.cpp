//* Question 162 :- Find Peak Element

//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        if(n==1) return 0;
        else if(arr[0]>arr[1]) return 0;
        else if(arr[n-1]>arr[n-2]) return n-1;
        else
        {
           for(int i=1;i<=(n-2);i++)
           {
                if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
                return i;
           }
        }
        return -1;
    }
};


//! Method - 2
//? Time Complexity =   O(log n)
//? Space Complexity =   O(1)


class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        if(n==1) return 0;
        else if(arr[0]>arr[1]) return 0;
        else if(arr[n-1]>arr[n-2]) return n-1;
        else
        {
            int st = 1;
            int end = n-2;

            while( st <= end )
            {
                int mid = st + (end-st)/2;

                if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1])
                return mid;

                else if(arr[mid]>arr[mid-1]) st = mid + 1;

                else end = mid - 1;
            }
        }
        return -1;
    }
};



