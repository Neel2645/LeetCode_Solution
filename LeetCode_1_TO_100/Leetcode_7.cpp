//! Question 7 -  Reverse Integer


//* Method - 1
//? Time Complexity - O(log n)
//? Space Complexity - O(1)

class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int n=x;
        if(x==0) ans=0;
        while(n!=0)
        {
            int rem=n%10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10)
                 ans=0;
            else  ans=ans*10+rem;
            n/=10;
        }
        return ans;
    }

};



//* Method - 2
//? Time Complexity - O(n)
//? Space Complexity - O(1)

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            swap(s[i++],s[j--]);
        }
        long long ans = stoll(s);
        if( ans < INT_MIN or ans > INT_MAX ) return 0;
        int n = stoi(s);
        if(x<0) return (-1)*n;
        
        return n;
    }
};