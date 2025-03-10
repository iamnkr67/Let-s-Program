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
        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;

        int n = 0;
        while(curr) {
            n++;
            curr = curr->next;
        }
        curr = head;

        while(n >= k) {
            ListNode* groupStart = curr;
            ListNode* prev = NULL;
            ListNode* next = NULL;

            for(int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupEnd->next = prev;
            groupStart->next = curr;
            prevGroupEnd = groupStart;

            n -= k;
        }
        return dummy->next;
    }
};