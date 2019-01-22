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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        
        ListNode* prev = nullptr;
        while (right) {
            ListNode* next = right->next;
            right->next = prev;
            prev = right;
            right = next;
        }
        // prev is head of right list
        merge(head, prev);
    }
    
private:
    void merge(ListNode* left, ListNode* right) {
        while (left && right) {
            ListNode* ln = left->next;
            ListNode* rn = right->next;
            left->next = right;
            right->next = ln;
            left = ln;
            right = rn;
        }
    }
};
