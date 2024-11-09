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