//* Question 151 - Reverse Words in a String

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n)  


class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string temp = "";
        string ans = "";

        while(ss>>temp)
        {
            reverse(temp.begin(),temp.end());
            ans += temp + " ";
        }

        ans.pop_back();
        return ans;
    }
};



//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "";
        string temp = "";

        while( ss >> temp )
        {
            ans = temp + " " + ans;
        }
        ans.pop_back();
        return ans;
    }
};


//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(n)


class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(s[i]==' ') i++;

        while(s[j]==' ')j--;

        string ans = "";
        while( i <= j )
        {
            string temp = "";
            while( i<=j and s[j]!=' ')
            {
                temp = s[j] + temp;
                j--;
            }

            while(i<=j and s[j]==' ') j--;

            ans += temp + " ";
        }
        ans.pop_back();
        return ans;
    }
};

//! Method - 4
//? Time Complexity - O(n)  
//? Space Complexity - O(1)


class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int n = s.size()-1;
        int i = 0;
        int start = 0;
        int end = 0;

        while( i <= n )
        {
            while( i<=n and s[i]!=' ')
            {
                s[end++] = s[i++];
            }

            if( start < end )
            {
                reverse(s.begin()+start , s.begin()+end);

                s[end] = ' ';
                end++;

                start = end;
            }

            i++;
        }
        return s.substr(0,end-1);

    }
};


//! Method - 5
//? Time Complexity - O(n)  
//? Space Complexity - O(n)

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size()-1;

        string ans = "";

        while( i <= n )
        {
            string temp = "";
            while(i<=n and s[i]==' ') i++;

            while(i<=n and s[i]!=' ')
            {
                temp += s[i];
                i++;
            }

            if(temp.size() > 0)
            {
                ans = temp + " " + ans;
            }
        }
        ans.pop_back();
        return ans;
    }
};

