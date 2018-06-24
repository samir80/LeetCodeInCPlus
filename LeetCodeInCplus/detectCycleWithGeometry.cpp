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
        ListNode* retNode = NULL;
        int find = 0;
        /*detect whether has a cycle*/
        if(head == NULL)
            return retNode;
        ListNode* slow = head;

        ListNode* fast = head;

        while(slow->next != NULL && fast->next != NULL && fast->next->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow || fast->next == slow){
                find = 1;    
                break;
            }
            
        }
           
        
        /*find the cycle begin node*/
        if(find == 1){
            if(fast ->next =  slow)
                slow = slow->next;
                fast = head;
                while(fast){
                    if(fast == slow){
                        retNode = fast;
                        break;
                    }                
                    fast = fast->next;
                    slow = slow->next;
                }
        }
        
        return retNode;
        
    }
};
