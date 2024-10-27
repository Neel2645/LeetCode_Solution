//* Question 215 --->  Kth Largest Element in an Array


//! Method - 1
//? Time Complexity - O(n logn)
//? Space Complexity - O(1) 

class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end(),greater<int>());
        return arr[k-1];
    }
};


//! Method - 2
//? Time Complexity - O(n logk)
//? Space Complexity - O(k) 


class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int &num: arr)
        {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};