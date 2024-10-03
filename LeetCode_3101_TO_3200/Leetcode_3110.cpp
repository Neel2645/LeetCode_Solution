//* Question 3110 :- Score of a String


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;

        for(int i=0;i<s.size()-1;i++)
        {
            ans += abs(s[i]-s[i+1]);
        }
        
        return ans;
    }
};