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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 or head == NULL or head->next == NULL){
            return head;
        }
        int n = 1;
        ListNode* last = head;
        ListNode* first = head;
        ListNode* NK = head;
        while(last->next != NULL){
            n++;
            last = last->next;
        }
        k = k % n;
        if(k == 0){
            return head;
        }
        int c = n - k , count = 1;
        while(NK){
            if(count == c){
                break;
            }
            NK = NK->next;
            count++;
        }
        ListNode* NKI = NK->next;
        last->next = head;
        NK->next = NULL;
        return NKI;
    }
};