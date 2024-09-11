//* Question 328 --->  Odd Even Linked List


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* list1 = new ListNode(-1);
        ListNode* list2 = new ListNode(-1);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        int i = 1;

        while(head)
        {
            if(i%2!=0)
            {
                temp1->next = head;
                temp1 = temp1->next;
            }
            else
            {
                temp2->next = head;
                temp2 = temp2->next;
            }
            head = head->next;
            i++;
        }
        
        temp1->next = list2->next;
        temp2->next = NULL;

        return list1->next;
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;

        vector<int> v;
        ListNode* temp = head;

        while(temp and temp->next)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }

        if(temp!=NULL) v.push_back(temp->val);
        temp = head->next;

        while(temp and temp->next)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }

        if(temp) v.push_back(temp->val);
        temp = head;
        
        int i = 0;
        while(temp)
        {
            temp->val = v[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};