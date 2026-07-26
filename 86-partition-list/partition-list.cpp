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
    ListNode* partition(ListNode* head, int x) {

        ListNode *before = new ListNode(-1);
        ListNode *after = new ListNode(-1);
        ListNode *b = before;
        ListNode *a = after;
        ListNode *temp = head;
        while(temp != NULL){
            if(temp->val < x){
                ListNode *temp1 = new ListNode(temp->val);
                b->next = temp1;
                b = b->next;           }
                temp = temp->next;
        } 

        temp = head;
        while(temp != NULL){
            if(temp->val >= x){
                ListNode *temp2 = new ListNode(temp->val);
                a->next = temp2;
                a = a->next;           }
                temp = temp->next;
        }
        b->next = after->next;
        head = before->next;
        delete after;
        delete before;
        return head;
        
    }
};