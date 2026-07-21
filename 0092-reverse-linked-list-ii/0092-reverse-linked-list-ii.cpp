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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL;
        ListNode* t = head;
        ListNode* before = NULL;
        ListNode* curr = t;
        int pos = 1;
        int times = right - left + 1;
        while(t != NULL and pos < left){
            if(pos < left){
                before = t;
                t =  t->next;
                pos++;
                continue;
            }
        }
         //position is greater time to reverse the linkedlist
        curr = t;
        for(int i=0;i<times;i++){
                ListNode* k = curr->next;
                curr->next = prev;
                prev = curr;
                curr = k;
        }
            t->next = curr;
            if(before){
                before->next = prev;
                return head;
            }
            return prev;
    }
};