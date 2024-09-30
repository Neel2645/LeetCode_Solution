//* Question 225 --->  Implement Stack using Queues

//! Method - 1
//? Time Complexity - O(1) For Push, O(N) For Pop ,Top , Empty
//? Space Complexity - O(n) 


class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int s = q.size()-1;
        for(int i=0;i<s;i++)
        {
            q.push(q.front());
            q.pop();
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
         int s = q.size();
        for(int i=1;i<s;i++)
        {
            q.push(q.front());
            cout<<q.front()<<" ";
            q.pop();
        }
        int x = q.front();
        q.push(x);
        q.pop();
        return x;
    }
    
    bool empty() {
        return q.size()==0;
    }
};


//! Method - 2
//? Time Complexity - O(1) For Push, Pop ,Top , Empty
//? Space Complexity - O(1) 


class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        int s =q.size();
        for(int i=1;i<s;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        int x = q.front();
        return x;
    }
    
    bool empty() {
        return q.size()==0;
    }
};



//! Method - 3
//? Time Complexity - O(1) For Push,Empty and O(n) for pop,top
//? Space Complexity - O(n) 

class MyStack {
public:

    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1) 
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        swap(q1,q2);
        return x;
    }
    
    int top() {
        while(q1.size()!=1) 
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        q2.push(x);
        swap(q1,q2);
        return x;
    }
    
    bool empty() {
        return q1.size()==0;
    }
};
