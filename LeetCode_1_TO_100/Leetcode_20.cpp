// Question - 20 ---> valid parentheses 
// Time  Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')st.push(s[i]);

            else
            {
                if(s[i]==')' && st.size()!=0 &&st.top()=='(')st.pop();
                else if(s[i]==']' && st.size()!=0 && st.top()=='[')st.pop();
                else if(s[i]=='}' && st.size()!=0 && st.top()=='{')st.pop();
                else return false;
            }
        }
        if(!st.empty())return false;

       return true;
    }
};




