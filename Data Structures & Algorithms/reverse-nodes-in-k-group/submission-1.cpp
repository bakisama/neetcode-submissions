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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // have a pointer at the point of separation and one just before it
        if (!head || k == 1)
            return head;
        ListNode dummy;
        dummy.next = head;
        ListNode* curr = &dummy;
        while (true) {
            ListNode* fast = curr;

            for (int i = 0; i < k; i++) {
                fast = fast->next;

                if (!fast)
                    return dummy.next;
            }
            ListNode* groupNext = fast->next;
            ListNode* prev = groupNext;
            ListNode* node = curr->next;

            while (node != groupNext) {
                ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                node = temp;
            }

            // Connect previous part to reversed group
            ListNode* temp = curr->next;
            curr->next = fast;
            curr = temp;
        }
    }
};