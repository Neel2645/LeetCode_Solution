//* Question 1894 ---  Find the Student that Will Replace the Chalk

//! Method - 1
//? Time limit exceed

//? Time  Complexity  - O(k/sum * n) 
//? Space Complexity - O(1)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true)
        {
            for(int i=0;i<chalk.size();i++)
            {
                if(k<chalk[i]) return i;
                k = k - chalk[i];
            }
        }
        return -1;
    }
};



//! Method - 2
//? Time  Complexity  - O(n) 
//? Space Complexity - O(1)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0;i<chalk.size();i++)
        {
            sum += chalk[i];

            if(k < sum ) return i;
        }
        k = (long long)k % sum;
        for(int i=0;i<chalk.size();i++)
        {
            if( k < chalk[i] ) return i;

            k = k - chalk[i];
        }
        return -1;
    }
};



//! Method - 3
//? Time  Complexity  - O(n) 
//? Space Complexity - O(n)


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> pref(n);
        pref[0] = chalk[0];
        for(int i = 1; i < n; i++)
            pref[i] = chalk[i] + pref[i-1];
        k %= pref[n-1];
        int i = 0, j = n-1, ans;
        while(i<=j){
            int mid = (i+j)/2;
            if(pref[mid] <= k)
                i = mid+1;
            else
                ans = mid, j = mid-1;
        }
        return ans;
    }
};
