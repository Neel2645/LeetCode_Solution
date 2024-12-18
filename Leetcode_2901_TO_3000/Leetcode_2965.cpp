//* Question 2965 ---> Find Missing and Repeated Values


//! Method - 1
//? Time Complexity - O(n^2)
//? Space Complexity - O(n^2) 

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(2,0);
        int p = n*n;
        int actualSum = p * (p+1) / 2;
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum += grid[i][j];
                if(mp.find(grid[i][j])!=mp.end()) 
                {
                    ans[0] = grid[i][j];
                }
                mp[grid[i][j]]++;
            }
        }

        ans[1] = actualSum + ans[0] - sum ;
        return ans;
    }
};


//! Method - 2
//? Time Complexity - O(n^2)
//? Space Complexity - O(n^2) 

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>vec(n*n +1,0);
        for(auto & it: grid){
            for(auto & i: it){
                vec[i]++;
            }
        }
        int a,b;
        for(int i=1;i<=n*n;i++){
            if(vec[i]==2) a = i;
            if(vec[i]==0) b = i;
        }
        return {a,b};
    }
};