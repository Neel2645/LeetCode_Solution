//* Question 703 :- Kth Largest Element in a Stream


//! Method - 1
//? Time Complexity =   O(LogK) ForAdd , O(NLogK) For Constructor
//? Space Complexity =   O(k)

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &num : nums)
        {
            pq.push(num);
            if(pq.size()>K) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();

        return pq.top();
    }
};

