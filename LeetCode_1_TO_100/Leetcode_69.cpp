//! Question 69 -  SQRT(X)


//* Method - 1
//? Time Complexity - O(1)
//? Space Complexity - O(1)


class Solution {
public:
    int mySqrt(int x) {
        return (int)sqrt(x);
    }
};


//* Method - 2
//? Time Complexity - O(log x)
//? Space Complexity - O(1)


class Solution {
public:
    int mySqrt(int x) {
        return pow(x,0.5);
    }
};



//* Method - 3
//? Time Complexity - O(x)
//? Space Complexity - O(1)

class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;

        for(int i=1;i<=x;i++)
        {
            long long a = i;
            if(a*a <= x) ans = i;
            else break;
        }
        return ans;
    }
};


//* Method - 4
//? Time Complexity - O( log x )
//? Space Complexity - O(1)


class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;

        int low = 1;
        int high = x;

        while( low <= high )
        {
            long long mid = low + (high-low)/2;

            if(mid*mid <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
        
    }
};


//* Method - 5
//? Time Complexity - O( log x )
//? Space Complexity - O(1)

class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;

        while( low <= high )
        {
            long long mid = low + (high-low)/2;

            if(mid*mid <= x)  low = mid + 1;

            else high = mid - 1;
        }
        return high;
        
    }
};