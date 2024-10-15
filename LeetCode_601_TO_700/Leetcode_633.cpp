//! Question 633 -  Sum of Square Number


//* Method - 1
//? Time Complexity - O(c)
//? Space Complexity - O(1)

class Solution {
public:
    bool SquareRoot(int n)
    {
        long long a = sqrt(n);
        return (a*a == n);
    }

    bool judgeSquareSum(int c) {
        int a = 0;
        int b = c;

        while(a<=b)
        {
            if(SquareRoot(a) and SquareRoot(b)) return true;
            a++;
            b--;
        }
        return false;
    }
};



//* Method - 2
//? Time Complexity - O(sqrt(c))
//? Space Complexity - O(1)


class Solution {
public:
    bool SquareRoot(int n)
    {
        long long a = sqrt(n);
        return (a*a == n);
    }

    bool judgeSquareSum(int c) {
        int a = 0;
        int b = c;

        while(a<=b)
        {
            if(SquareRoot(a) and SquareRoot(b)) return true;
            else if(!SquareRoot(b))
            {
                b = (int)(sqrt(b)) * (int)(sqrt(b));
                a = c - b;
            }
            else
            {
                a = ((int)sqrt(a) + 1) * ((int)sqrt(a) + 1);
                b = c - a;
            }
        }
        return false;
    }
};



//* Method - 3
//? Time Complexity - O(c)
//? Space Complexity - O(1)


class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = c;

        while(a<=b)
        {
            long long ans = a*a + b*b;

            if(ans==c) return true;
            else if(ans>c) b--;
            else a++;
        }
        return false;
    }
};


//* Method - 4
//? Time Complexity - O(sqrt(c))
//? Space Complexity - O(1)


class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = sqrt(c);

        while(a<=b)
        {
            long long ans = a*a + b*b;

            if(ans==c) return true;
            else if(ans>c) b--;
            else a++;
        }
        return false;
    }
};