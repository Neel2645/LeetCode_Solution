//* Question 53 ---> Maximum Subarray

//! Method - 1
//? Time Complexity - O(n^3)  
//? Space Complexity - O(1) 

//? Time Limit Exceeded in this approach

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        long long maxi = LLONG_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                long long sum = 0;
                for(int k=i;k<=j;k++)
                {
                    sum += arr[k];
                }
                if(maxi < sum) maxi = sum;
            }
        }
        return maxi;
    }
};

//! Method - 2
//? Time Complexity - O(n^2)  
//? Space Complexity - O(1) 


//? Time Limit Exceeded in this approach

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        long long maxi = LLONG_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            long long sum = 0;
            for(int j=i;j<n;j++)
            {
                sum += arr[j];
                if(maxi < sum) maxi = sum;
            }
        }
        return maxi;
    }
};


//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 

//? Using Kadane's Algorithm here 

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++)
        {
            sum += arr[i];

            maxi = max(maxi,sum);

            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};