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
        // 1 -> 9
        // +
        // 9 -> 9 -> 1 -> 1
        // =
        // 0 -> 9 -> 2 -> 1
        ListNode *ret = new ListNode;
        ListNode * head = ret;
        int digit_sum = 0;
        while(true)
        {
            ret->val = (digit_sum + l1->val + l2->val) % 10;
            digit_sum = (digit_sum + l1->val + l2->val) / 10;
            l1->val = 0, l2->val = 0;
            if(l1->next == NULL && l2->next == NULL && !digit_sum)
                break;
            if(l1->next != NULL)l1 = l1->next;
            if(l2->next != NULL)l2 = l2->next;
            ret->next = new ListNode;
            ret = ret->next;
        }
        return head;
    }
};
