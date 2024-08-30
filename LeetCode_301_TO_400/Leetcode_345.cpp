//* Question 345 - Reverse Vowels of a String

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 

class Solution {
public:
    bool isVowels(char &ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || 
           ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' )
        return true;

        return false;
    }

    string reverseVowels(string s) {
        int n = s.size();
        string vow = "";
        for(int i=0;i<n;i++)
        {
            if(isVowels(s[i])) vow.push_back(s[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(isVowels(s[i])) 
            {
                s[i] = vow[vow.size()-1];
                vow.pop_back();
            }
        }
        return s;
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 

class Solution {
public:
    bool isVowels(char &ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || 
           ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' )
        return true;

        return false;
    }

    string reverseVowels(string s) {
        int n = s.size();
        stack<char> vow;
        for(int i=0;i<n;i++)
        {
            if(isVowels(s[i])) vow.push(s[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(isVowels(s[i])) 
            {
                s[i] = vow.top();
                vow.pop();
            }
        }
        return s;
    }
};


//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 


class Solution {
public:
    bool isVowels(char &ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || 
           ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' )
        return true;

        return false;
    }

    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;

        while( i <= j )
        {
           if(!isVowels(s[j])) j--;

           else if(!isVowels(s[i])) i++;

           else
           {
                swap(s[i],s[j]);
                i++;
                j--;
           }
        }
        return s;
    }
};