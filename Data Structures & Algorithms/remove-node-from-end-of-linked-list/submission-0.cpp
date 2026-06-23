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
        int N = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            N++;
            curr = curr->next;
        }

        int i = 0;
        ListNode* prev = nullptr;
        curr = head;
        while(i++ != N - n) {
            prev = curr;
            curr = curr -> next;
        }

        if(prev == nullptr) {
            return head -> next;
        }

        prev -> next = curr -> next;
        return head;
    }
};
