//* Question 1446 - Consecutive Characters

//! Method - 1 (Two pointer approach)
//? Time Complexity -  O(n)
//? Space Complexity - O(1)


class Solution {
public:
    int maxPower(string s) {
        int mx = 0;
        int count = 1;
        int j = 0;
        int n = s.size();

        for(int i=1;i<n;i++)
        {
            if(s[i] == s[j]) count++;
            else
            {
                mx = max(mx,count);
                j = i;
                count = 1;
            }
        }

        mx = max(mx,count);
        return mx;
    }
};


//! Method - 2 (Two Pointer Approach + Find Sliding Window)
//? Time Complexity -  O(n)
//? Space Complexity - O(1)


class Solution {
public:
    int maxPower(string s) {
        int mx = 0;
        int j = 0;
        int n = s.size();
        int i = 1;
        for(i;i<n;i++)
        {
            if(s[i] == s[j]) continue;
            else
            {
                mx = max(mx,i-j);
                j = i;
            }
        }

        mx = max(mx,i-j);
        return mx;
    }
};