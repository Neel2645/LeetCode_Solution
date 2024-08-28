//* Question 9 - Palindrome Number

//! Method - 1
//? Time Complexity - O(log n)  
//? Space Complexity - O(1) 

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long rev = 0;
        int temp = x;

        while(temp != 0)
        {
            int rem = temp % 10;
            rev = rev * 10 + rem;
            temp /= 10;
        }
        if(x == rev)return true;

        return false;
    }
};


//! Method - 2
//? Time Complexity - O(log n)  
//? Space Complexity - O(log n) 


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;

        string s1 = to_string(x);
        string s2 = s1;
        reverse(s1.begin(),s1.end());
        return s1==s2;
    }
};


//! Method - 3
//? Time Complexity - O(log n)  
//? Space Complexity - O(log n)


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        stack<int> st;
        int temp = x;
        while(temp)
        {
            st.push(temp%10);
            temp /= 10;
        }
        temp = x;
        while(temp)
        {
            if(st.top() != temp%10)return false;

            st.pop();
            temp /= 10;
        }
        return true;
    }
};