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
#define node ListNode
#define data val
#define ed endl
ListNode* reverse(ListNode* head , int times){
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(times--){
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head->next = curr;
    return prev;
}
    ListNode* swapPairs(ListNode* head) {
        int size = 2;
        ListNode* left = head;
        ListNode* right ;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;
        if (head == NULL || head->next == NULL){
            return head;
        }
        while (left != NULL && left->next != NULL) {
            ListNode* nextleft = left->next->next;
            ListNode* newHead = reverse(left, size);
            if (prevleft == NULL) {
                res = newHead;
            }
            else {
                prevleft->next = newHead;
            }
            prevleft = left;
            left = nextleft;
        }
        if (prevleft != NULL){
            prevleft->next = left;
        }
        return res;
    }
};