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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int copy = n;
        ListNode* slow = head;
        ListNode* fast = head;
        while(copy){
            copy--;
            fast = fast->next;
        }
        ListNode* prev = nullptr;
        while(fast!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev == nullptr) {
            return head->next;
        }
        prev->next = slow->next;
        return head;
    }
};
