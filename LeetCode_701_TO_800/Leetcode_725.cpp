//* Question 725 ---> Split Linked List in Parts

//! Method - 1
//? Time Complexity - O(n)  
//? if we do not considered the space of the vector which we are going to return the  it is O(1) 
//? Space Complexity - O(k) 



class Solution {
public:
    int lengthOfLL(ListNode* head)
    {
        int n = 0;
        while(head)
        {
            n++;
            head = head->next;
        }
        return n;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        int len = lengthOfLL(head);
        int partsSize = (len/k);
        int rem = (len % k);

        while(head)
        {
            ListNode* dummy = new ListNode(-1);
            ListNode* dp = dummy;

            for(int i=0;i<partsSize;i++)
            {
                dp->next = head;
                dp = dp->next;
                head = head->next;
            }

            if(rem!=0)
            {
                dp->next = head;
                dp = dp->next;
                head = head->next;
                rem--;
            }

            dp->next = NULL;
            ans.push_back(dummy->next);
        }

        while(ans.size()!=k)
        {
            ans.push_back(NULL);
        }
        return ans;
    }
};


//! Method - 2
//? Time Complexity - O(n)  
//? if we do not considered the space of the vector which we are going to return the  it is O(1) 
//? Space Complexity - O(k) 


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;

        while(curr)
        {
            len++;
            curr = curr->next;
        }
        vector<ListNode*> ans(k,NULL);
        int partsSize = (len/k);
        int rem = (len % k);

        curr = head;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++)
        {
            ans[i] = curr;
            
            for(int i=1;i<=partsSize+(rem>0 ? 1 : 0);i++)
            {
                prev = curr;
                curr = curr->next;
            }

            if(prev) prev->next = NULL;
            rem--;
        }
        return ans;
    }
};