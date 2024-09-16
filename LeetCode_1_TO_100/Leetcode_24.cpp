//* Question 24 ---> Swap Nodes in Pairs

//! Method - 1
//? Time Complexity - O(n)  
//? Space Complexity - O(n) 


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;

        ListNode* newNode = swapPairs(head->next->next);
        ListNode* nextNode = head->next;
        head->next = newNode;
        nextNode->next = head;
        return nextNode;
    }
};