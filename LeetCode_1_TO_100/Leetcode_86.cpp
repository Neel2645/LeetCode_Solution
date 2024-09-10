//* Question 86 ---> Partition List 


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* low = new ListNode(-1);
        ListNode* high = new ListNode(-1);
        ListNode* tl = low;
        ListNode* th = high;

        while(head)
        {
            ListNode* temp = new ListNode(head->val);
            if(head->val < x)
            {
                tl->next = temp;
                tl = tl->next;
            }
            else
            {
                th->next = temp;
                th = th->next;
            }
            head = head->next;
        }
        tl->next = high->next;
        th->next = NULL;
        return low->next;
    }
};


//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* low = new ListNode(-1);
        ListNode* high = new ListNode(-1);
        ListNode* tl = low;
        ListNode* th = high;

        while(head)
        {
            if(head->val < x)
            {
                tl->next = head;
                tl = tl->next;
            }
            else
            {
                th->next = head;
                th = th->next;
            }
            head = head->next;
        }

        tl->next = high->next;
        th->next = NULL;

        return low->next;
    }
};