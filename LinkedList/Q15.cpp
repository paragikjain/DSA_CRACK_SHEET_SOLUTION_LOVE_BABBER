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
    ListNode* middleNode(ListNode* head) {
       if(head->next==NULL)
         return head;
        ListNode *slow=head,*fast=head->next;
      int count=0;
      while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        count++;
      }
      if(fast==NULL)
        return slow; 
      else
        return slow->next;
    }
};