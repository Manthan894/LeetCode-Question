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
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            //Check karuga ki cycle exist karati hai ki nahi
            if(fast == slow){
                //Now cycle exist so now let find starting point
                slow = head;
                while(slow != fast){
                    slow = slow-> next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};