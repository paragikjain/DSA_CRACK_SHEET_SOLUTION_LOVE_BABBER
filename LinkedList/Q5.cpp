/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        
        ListNode* slow = head , *fast = head;
        
        // find the intersection point of slow and fast pointers
        do{
            if(fast->next == NULL || fast->next->next == NULL)  // if loop doesnt exists then list will come to an end after soome time
                return NULL;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow!=fast);
            
        // finding where the loop started(at which node)
        
        slow = head;
        
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};