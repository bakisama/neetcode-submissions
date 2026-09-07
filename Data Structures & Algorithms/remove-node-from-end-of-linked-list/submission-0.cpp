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
        int size = 0;
        ListNode* slow = head;
        while(slow){
            slow = slow->next;
            size++;
        }
        int target = size - n;
        int current = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head; 
        while(target!=current){
            prev = curr;
            curr = curr->next;
            current++;
        }
         if (prev == nullptr) {
            return head->next;
        }
        prev->next = curr->next;
        return head;
    }
};
