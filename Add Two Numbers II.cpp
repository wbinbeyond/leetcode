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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* p = l1;
        ListNode* q = l2;
        while (p) {
            s1.push(p->val);
            p = p->next;
        }
        while (q) {
            s2.push(q->val);
            q = q->next;
        }
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
        while (!s1.empty() || !s2.empty()) {
            int x = s1.empty() ? 0 : s1.top();
            int y = s2.empty() ? 0 : s2.top();
            int sum = x + y + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
        }
        if (carry == 1) {
            cur->next = new ListNode(1);
        }
        return reverse(dummy.next);
    }
    ListNode* reverse(ListNode* head) {
        if (!head->next) return head;
        ListNode* rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
};
