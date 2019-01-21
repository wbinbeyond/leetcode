/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                // this keeps the first one of the duplicates
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }
};
*/

class Solution {
public: 
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy = ListNode(0);
        dummy.next = head;
        head = &dummy;
        while (head->next && head->next->next) {
            if (head->next->val == head->next->next->val) {
                // this removes all duplicates
                // int val = head->next->val;
                // while (head->next && head->next->val == val) {
                //    head->next = head->next->next;
                // }
                
                // this keeps the last one of the duplicates
                head->next = head->next->next;
            }
            else {
                head = head->next;
            }
        }
        return dummy.next;
    }
};
