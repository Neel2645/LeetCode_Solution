//* Question 342 --->   Power of Four


//! Method - 1
//? Time Complexity =   O(log n)
//? Space Complexity =   O(log n) 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        if(n%4!=0) return false;

        return isPowerOfFour(n/4);
    }
};

//! Method - 2
//? Time Complexity =   O(log n)
//? Space Complexity =   O(1) 


class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;

        while(n%4==0) n = n / 4;

        return n == 1;
    }
};

//! Method - 3
//? Time Complexity =   O(1)
//? Space Complexity =   O(1) 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int ans = 1;
        for(int i=0;i<31;i++)
        {
            if(ans==n) return true;

            if(ans < INT_MAX/4 and ans > INT_MIN/4) ans = ans * 4;
        }
        return false;
    }
};


//! Method - 4
//? Time Complexity =   O(1)
//? Space Complexity =   O(1) 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double ans = log10(n) / log10(4);
        return ceil(ans) == floor(ans);
    }
};

//! Method - 5
//? Time Complexity =   O(1)
//? Space Complexity =   O(1) 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        
        int pos = 1;
        int one_pos = 1;
        int noo = 0;

        while(n)
        {
            if(n & 1)
            {
                noo++;
                one_pos = pos;
            }
            n = n>>1;
            pos++;
        }

        return (one_pos & 1) and (noo==1);
    }
};

//! Method - 6
//? Time Complexity =   O(1)
//? Space Complexity =   O(1) 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int ans = log(n) / log(4);
        return pow(4,ans)==n;
    }
};

//! Method - 7
//? Time Complexity =   O(1)
//? Space Complexity =   O(1) 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;

        bool ans1 = n & (n-1);
        bool ans2 = (n-1)%3;

        return (ans1==0) and (ans2==0);
    }
};