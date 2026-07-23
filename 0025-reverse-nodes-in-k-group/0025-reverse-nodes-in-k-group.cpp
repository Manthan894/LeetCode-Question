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

    ListNode* reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (k--) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = curr;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1){
            return head;
        }
        ListNode* left = head;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;
        while (left != NULL) {
            ListNode* right = left;
            for (int i = 1; i < k; i++) {
                if (right == NULL)
                    break;
                right = right->next;
            }
            if (right == NULL) {
                if (prevleft)
                    prevleft->next = left;
                break;
            }
            ListNode* nextleft = right->next;
            ListNode* newHead = reverse(left, k);
            if (prevleft == NULL){
                res = newHead;
            }
            else{
                prevleft->next = newHead;
            }
            prevleft = left;
            left = nextleft;
        }

        if (res == NULL){
            return head;
        }
        return res;
    }
};