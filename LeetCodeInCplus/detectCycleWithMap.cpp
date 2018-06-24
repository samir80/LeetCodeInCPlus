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
            map<void*,int> mapListRef;
            ListNode* pNode = head;
            while(pNode != NULL){
                if(mapListRef.find(pNode) != mapListRef.end())
                    break;
                else
                    mapListRef.insert(pair<void*,int>(pNode,1));
                pNode = pNode->next;
            }
            retNode = pNode;
        }
        
        return retNode;
        
    }
};
