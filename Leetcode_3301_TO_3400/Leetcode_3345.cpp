//* Question 3345 ---> Smallest Divisible Digit Product I

//! Method - 1
//? Time Complexity - O(log n)
//? Space Complexity - O(1)


class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int temp = n;
            int digit = 1;
            while (temp) {
                digit *= (temp % 10);
                temp /= 10;
            }
            if (digit % t == 0)
                return n;
            n++;
        }
        return -1;
    }
};


//! Method - 2
//? Time Complexity - O(T * log n)
//? Space Complexity - O(1)

class Solution {
public:
    int smallestNumber(int n, int t) {
        if(t==1) return n;
        while(true)
        {
            string s = to_string(n);
            int p = 1;
            for(int i=0;i<s.size();i++) p = p * (s[i]-'0');
            if(p % t == 0) return n;
            n++; 
        }
        return -1;
    }
};