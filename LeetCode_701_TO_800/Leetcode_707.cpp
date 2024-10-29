//* Question 707 :- Design Linked List


//! Method - 1
//? Time Complexity =  O(n)
//? Space Complexity =   O(k)


class Node
{
    public:
    int val;
    Node* next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size = 0;
    MyLinkedList() {
       head = tail = NULL;
       size = 0;
    }
    
    int get(int index) {
        if(index>=size) return -1;
        Node* temp = head;
        for(int i=0;i<index;i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        if(size==0) 
        {
            head = tail = temp;
        }
        else
        {
           temp->next = head;
           head = temp;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(size==0) 
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return ;
        else if(index==0) addAtHead(val);
        else if(index==size) addAtTail(val);
        else
        {
            Node* temp = new Node(val);
            Node* t = head;
            for(int i=1;i<index;i++)
            {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) return;
        else if(index==0) head = head->next;
        else if(index==size-1) 
        {
            Node* t = head;
            while(t->next!=tail)
            {
                t = t->next;
            }
            t->next = NULL;
            tail = t;
        }
        else
        {
            Node* t = head;
            for(int i=1;i<index;i++)
            {
                t = t->next;
            }
            t->next = t->next->next;
        }
        size--;
    }
};

