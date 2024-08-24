//* Question :- Check if the Sentence Is Pangram


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)

class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;

        map<char,int> mp;
        
        for(char &ch : s)
        mp[ch]++;

        return mp.size()==26;
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)


class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;

        unordered_set<char> st(s.begin(),s.end());

        return st.size()==26;
    }
};

//! Method - 3
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;

        for(int i=0;i<26;i++)
        {
            char ch = 'a' + i;
            if(s.find(ch) == string::npos) return false;
        }

        return true;
    }
};

//! Method - 4
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)

//* Some of my friends are think , we use vector therefore our space complexity will be O(n) but here
//* we use constant extra space which is always constant so that it would be O(1).  

class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;

        vector<int> v(26,0);

        for(char &ch : s)
        {
            int idx = ch - 'a';
            v[idx]++;
        }

        for(int i=0;i<26;i++)
        {
            if(v[i] == 0) return false;
        }

        return true;
    }
};


//! Method - 5
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    bool checkIfPangram(string s) {
        int tsb = 0;
        for(char &ch: s)
        {
            int idx = ch - 'a';
            int bits = 1<<idx;
            tsb = tsb | bits;
        }

        return tsb == (1<<26)-1;
    }
};