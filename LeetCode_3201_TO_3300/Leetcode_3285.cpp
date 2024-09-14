//* Question 3285 ---> Find Indices of Stable Mountains

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(1)  


class Solution {
public:
    vector<int> stableMountains(vector<int>& h, int th) {
        vector<int> ans;
        for(int i=1;i<h.size();i++)
        {
            if(h[i-1]>th) 
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};