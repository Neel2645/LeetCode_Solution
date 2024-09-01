//* Question 326 -  Power of Three

//! Method - 1
//? Time Complexity - O(1)  
//? Space Complexity - O(1) 

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
         double ans= log10(n)/log10(3);
         return ceil(ans)==floor(ans);
    }
};

//! Method - 2
//? Time Complexity - O(1)  
//? Space Complexity - O(1) 


class Solution {
public:
    bool isPowerOfThree(int n) {
        double ans=1;
        if(n<=0)return false;
        for(int i=1;i<=31;i++)
        {
            if(ans==n)return true;
            if(ans<INT_MAX/3 and ans>INT_MIN/3)
            ans=ans*3;
        }
        return false;
    }
};

//! Method - 3
//? Time Complexity - O(log n)  
//? Space Complexity - O(log n) 


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;

        if(n==1) return true;

        if(n%3!=0) return false;

        return isPowerOfThree(n/3);
    }
};

//! Method - 4
//? Time Complexity - O(log n)  
//? Space Complexity - O(1) 

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;

        while(n%3==0) n /= 3;

        return n==1;
    }
};

