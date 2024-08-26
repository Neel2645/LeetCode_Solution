//* Question - Remove Duplicates from Sorted List II

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        ListNode* temp = head;

        while(temp)
        {
            mp[temp->val]++;
            temp = temp->next;
        }

        ListNode* newNode = new ListNode(-1);
        temp = newNode;
        auto itr = mp.begin();
        while(itr != mp.end())
        {
            if(itr->second==1)
            {
                temp->next = new ListNode(itr->first);
                temp = temp->next;
            }
            itr++;
        }
        return newNode->next;
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? Space Complexity - O(1) 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        temp->next = head;

        while(head)
        {
            if(head->next and head->val == head->next->val)
            {
                while(head->next and head->val == head->next->val)
                head = head->next;

                temp->next = head->next;
            }

            else temp = temp->next;

            head = head->next;
        }

        return dummy->next;
    }
};
