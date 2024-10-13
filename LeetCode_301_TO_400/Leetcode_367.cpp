//! Question 367 -  Valid Perfect Square


//* Method - 1
//? Time Complexity - O(1)
//? Space Complexity - O(1)


class Solution {
public:
    bool isPerfectSquare(int num) {
        long long x = sqrt(num);
        return (x*x == num);
    }
};


//* Method - 2
//? Time Complexity - O(n)
//? Space Complexity - O(1)

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i=1;i<=num;i++)
        {
            if(i*i == num) return true;
            if(i*i > num) return false;

        }
        return false;
    }
};


//* Method - 3
//? Time Complexity - O(log n)
//? Space Complexity - O(1)


class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;

        while(low<=high)
        {
            long long mid = low + (high-low)/2;

            if(mid*mid == num) return true;

            else if(mid*mid < num) low = mid + 1; 

            else high = mid - 1;
        }
        return false;
    }
};