//* Question 143 ---> Reorder List

//! Method - 1
//? Time  Complexity  - O(n)
//? Space Complexity  - O(1)

class Solution {
public:
    
    ListNode* reversell(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reversell(slow->next);
        slow->next = NULL;
        ListNode* first = head;

        while(second)
        {
            ListNode* temp1 = first->next;
            first->next = second;
            ListNode* temp2 = second->next;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};


//! Method - 2
//? Time  Complexity  - O(n)
//? Space Complexity  - O(n)


class Solution {
public:
    
    ListNode* reversell(ListNode* head)
    {
       if(head==NULL or head->next==NULL) return head;

       ListNode* newHead = reversell(head->next);
       head->next->next = head;
       head->next = NULL;
       return newHead;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reversell(slow->next);
        slow->next = NULL;
        ListNode* first = head;

        while(second)
        {
            ListNode* temp1 = first->next;
            first->next = second;
            ListNode* temp2 = second->next;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};


//! Method - 3
//? Time  Complexity  - O(n)
//? Space Complexity  - O(n)


class Solution {
public:
    
    void reorderList(ListNode* head) {
      
      stack<ListNode*> st;
      ListNode* temp1 = head;

      while(temp1)
      {
        st.push(temp1);
        temp1 = temp1->next;
      }

      temp1 = head;
      ListNode* temp2 = head;
      ListNode* temp3 = head;
      int k = st.size()/2;

      while(k--)
      {
         temp2 = temp1->next;
         temp3 = st.top();
         st.pop();
         temp1->next = temp3;
         temp3->next = temp2;
         temp1 = temp2;
      }
     temp1->next = NULL;
    }
};




//! Method - 4
//? Time  Complexity  - O(n)
//? Space Complexity  - O(n)

class Solution {
public:
    ListNode* curr;
    void solve(ListNode* head)
    {
        if(head==NULL) return;

        solve(head->next);

        ListNode* temp = curr->next;
        if(curr->next==NULL) return;
        else if(head==curr)
        {
            head->next = NULL;
            return;
        }

        curr->next = head;
        head->next = (temp==head)?NULL:temp;
        curr = temp;
    }
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};