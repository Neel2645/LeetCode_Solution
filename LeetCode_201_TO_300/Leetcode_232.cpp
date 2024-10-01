//* Question 232 --->  Implement Queue using Stacks

//! Method - 1
//? Time Complexity - O(1) For Push and Empty , O(N) For Pop , peek
//? Space Complexity - O(1) For Push and Empty , O(N) For Pop , peek


class MyQueue {
public:
    stack<int> st;
    stack<int> temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()!=0)
        {
            temp.push(st.top());
            st.pop();
        }
        int x = temp.top();
        temp.pop();
        while(temp.size()!=0)
        {
            st.push(temp.top());
            temp.pop();
        }
        return x;
    }
    
    int peek() {
        while(st.size()!=0)
        {
            temp.push(st.top());
            st.pop();
        }
        int x = temp.top();
        while(temp.size()!=0)
        {
            st.push(temp.top());
            temp.pop();
        }
        return x;
    }
    
    bool empty() {
        return st.size()==0;
    }
};


//! Method - 2
//? Time  Complexity - O(1) For Push , Empty , peek and amortized O(1) for pop
//? Space Complexity - O(1) For Push ,Empty , peek and O(n) for pop


class MyQueue {
public:
    stack<int> st;
    stack<int> temp;
    int peekEle;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.size()==0)
        {
            peekEle = x;
        }
        st.push(x);
    }
    
    int pop() {
       if(temp.size()==0)
       {
         while(st.size()!=0)
        {
            temp.push(st.top());
            st.pop();
        }
       }
        int x = temp.top();
        temp.pop();
        return x;
    }
    
    int peek() {
       if(temp.size()) return temp.top();

       return peekEle;
    }
    
    bool empty() {
        return temp.size()==0 and st.size()==0;
    }
};


//! Method - 3
//? Time  Complexity - O(1) For Push , Empty and amortized O(1) for pop and peek
//? Space Complexity - O(1) For Push ,Empty and O(n) for pop and peek

class MyQueue {
public:
    stack<int> st;
    stack<int> temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
       if(temp.size()==0)
       {
         while(st.size()!=0)
        {
            temp.push(st.top());
            st.pop();
        }
       }
        int x = temp.top();
        temp.pop();
        return x;
    }
    
    int peek() {
        if(temp.size()==0)
       {
         while(st.size()!=0)
        {
            temp.push(st.top());
            st.pop();
        }
       }
        int x = temp.top();
        return x;
    }
    
    bool empty() {
        return temp.size()==0 and st.size()==0;
    }
};
