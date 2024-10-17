//* Question 2485 :- Find the Pivot Integer


//! Method - 1
//? Time Complexity =   O(n^2)
//? Space Complexity =   O(1)


class Solution {
public:
    int pivotInteger(int n) {
        for(int pivot=1;pivot<=n;pivot++)
        {
            int leftSum = 0;
            int rightSum = 0;

            for(int i=1;i<=pivot;i++)
            leftSum += i;

            for(int i=pivot;i<=n;i++)
            rightSum += i;

            if(leftSum == rightSum) return pivot;
        }
        return -1;
    }
};


//! Method - 2
//? Time Complexity =  O(n)
//? Space Complexity =  O(1)


class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n*(n+1)/2;
        for(int pivot=1;pivot<=n;pivot++)
        {
            int leftSum = pivot*(pivot+1)/2;
            int rightSum = totalSum - leftSum + pivot;

            if(leftSum == rightSum) return pivot;
        }
        return -1;
    }
};


//! Method - 3
//? Time Complexity =  O(n)
//? Space Complexity =  O(1)

class Solution {
public:
    int pivotInteger(int n) {
        int i = 1;
        int j = n;

        int leftSum = 1;
        int rightSum = n;

        while(i < j)
        {
            if(leftSum <= rightSum)
            {
                i++;
                leftSum += i;
            }
            else
            {
                j--;
                rightSum += j;
            }
        }
        return leftSum==rightSum ? i : -1;
    }
};


//! Method - 4
//? Time Complexity =  O(1)
//? Space Complexity =  O(1)

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n*(n+1)/2;
        int x = sqrt(totalSum);

        return (x*x == totalSum) ? x : -1;
    }
};


//! Method - 5
//? Time Complexity =  O(log n)
//? Space Complexity =  O(1)

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n*(n+1)/2;

        int low = 1;
        int high = n;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int x = mid * mid;
            if(x == totalSum) return mid;
            else if(x < totalSum) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};