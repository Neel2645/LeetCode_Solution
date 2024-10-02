//* Question 1903 :- Largest Odd Number in String


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size()-1;

        for(int i=n;i>=0;i--)
        {
            if((num[i] - '0') % 2 != 0 )
            {
                return num;
            }
            num.pop_back();
        }
        return "";
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size()-1;

        for(int i=n;i>=0;i--)
        {
            if((num[i] - '0') % 2 != 0 )
            {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};