//* Question 347 ---> Top K Frequent Elements

//! Method - 1
//? Time Complexity - O(n log k)
//? Space Complexity - O(n)


class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int> mp;  // O(n) space & time complexity

        for(auto &ele : arr)
        {
            mp[ele]++;
        }

        priority_queue<p,vector<p>,greater<p>> pq; // min heap 
        // O(n logk) space and time complexity

        for(auto it : mp)
        {
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans; // O(k) space complexity
        while(!pq.empty()) // O(k logk) time complexity
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};