//* Question :- Three Consecutive Odds


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%2!=0) count++;
            else count = 0;

            if(count==3) return true;
        }
        return false;
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)

//* Best Solution Using sliding window
//* Understand how to we use sliding window  

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3) return false;
        int count = 0;
        for(int i=0;i<3;i++)
        {
            if(arr[i]%2!=0) count++;
        }
        if(count==3) return true;

        for(int i=1;i<=(arr.size()-3);i++)
        {
            if(arr[i-1]%2!=0) count--;

            if(arr[i+2]%2!=0)count++;

            if(count==3) return true;
        }

        return false;
    }
};