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

