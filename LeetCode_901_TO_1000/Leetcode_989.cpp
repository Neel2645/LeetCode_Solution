//* Question 989 -  Add to Array-Form of Integer

//! n = length of the array
//! k = integer number

//* Method - 1
//? Time Complexity - O(max(n,log k))  
//? Space Complexity - O(log k) 


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& arr, int k) {
        for(int i=arr.size()-1;i>=0;i--)
        {
            int temp = arr[i] + k;
            arr[i] = temp % 10;
            k = temp / 10;
        }

        while(k!=0)
        {
            arr.insert(arr.begin(),k%10);
            k = k / 10;
        }
        return arr;
    }
};


//* Method - 2
//? Time Complexity - O(max(n,log k))  
//? Space Complexity - O(log k) 


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size() - 1;
        int carry = 0;

        for(int i=n;i>=0;i--)
        {
            int sum = num[i] + (k%10) + carry;
            num[i] = sum % 10;
            carry = sum / 10;
            k = k / 10;
            if( k==0 && carry==0) break;
        }

        while(k!=0)
        {
            int val = (k%10) + carry;
            num.insert(num.begin(),val%10);
            carry = val / 10;
            k = k / 10;
        }

        if(carry)
        {
            num.insert(num.begin(),carry);
        }
        return num;
    }
};