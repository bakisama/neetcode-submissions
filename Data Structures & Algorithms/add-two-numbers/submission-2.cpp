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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        int carry = 0;
        ListNode* curr = &dummy;
        while(l1 || l2 || carry){
            int sum = 0;
            int digit1 = 0;
            int digit2 = 0;
            if(l1) digit1 = l1->val;
            if(l2) digit2 = l2->val;
            sum = digit1 + digit2 + carry;
            carry = sum/10;
            sum = sum%10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;

        }
        return dummy.next;

    }
};
