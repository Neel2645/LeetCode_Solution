//* Question 24 ---> Swap Nodes in Pairs

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;

        ListNode* second = head->next;
        head->next = swapPairs(head->next->next);
        second->next = head;
        return second;
    }
};

//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        vector<int> odd;
        vector<int> even;

        ListNode* temp = head;
        while(temp)
        {
            odd.push_back(temp->val);
            temp = temp->next;
           if(temp) 
           {
                even.push_back(temp->val);
                temp = temp->next;
           }
        }
        temp = head;
        int i = 0;
        while(temp)
        {
            if(i<even.size())temp->val = even[i];
            temp = temp->next;
            if(temp)
            {
                 if(i<even.size())temp->val = odd[i];
                temp = temp->next;
            }
            i++;
        }
        return head;
    }
};


//! Method - 3
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;

        ListNode* temp = new ListNode(-1);
        ListNode* prev = temp;
        ListNode* curr = head;

        while(curr and curr->next)
        {
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return temp->next;
    }
};