//* Question 658 ---> Find K Closest Elements


//! Method - 1
//? Time Complexity - O(n log k)
//? Space Complexity - O(k)


class Solution {
public:
    typedef pair<int,int> p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<p> pq; // max heap
        vector<int> ans;
        for(auto &ele : arr)
        {
            pq.push({abs(x-ele),ele});
            if(pq.size()>k) pq.pop();
        }

        while(pq.size()>0)
        {
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};


//! Method - 2
//? Time Complexity - O(n log k)
//? Space Complexity - O(k)