/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL  || head->next == NULL || head->next->next == NULL)
           return;
        ListNode *slow = head;
        ListNode *fast = head;
    
        while(fast != NULL && fast->next != NULL){
        
            slow = slow->next;
            fast = fast->next->next;
        }
    
        ListNode *curr = slow->next;
         slow->next = NULL;
        ListNode *next = NULL;
         ListNode *prev = NULL;
         while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
         }
         
         ListNode *temp1 = head;
         ListNode *temp2 = prev;
         while(temp2){
            ListNode *m1 = temp1->next;
            ListNode *m2 = temp2->next;
            temp1->next = temp2;
            temp2->next = m1;
            temp1 = m1;
            temp2 = m2;
         }
        
    }
};