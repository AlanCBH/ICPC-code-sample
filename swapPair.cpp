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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = head;
        ListNode* prev = NULL;
        bool first = true;
        ListNode* new_head;
        while (tmp != NULL && tmp->next != NULL) {
            ListNode* next_tmp = tmp->next;
            tmp->next = next_tmp->next;
            next_tmp->next = tmp;
            if (first) { 
                first = false;
                new_head = next_tmp;
            } else {
                prev->next = next_tmp;
            }
            prev = tmp;
            tmp = tmp->next;
           
        }
        return new_head;
    }
};