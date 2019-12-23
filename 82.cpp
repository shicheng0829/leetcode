/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = head;
        ListNode *pre = dummy;
        while (cur)
        {
            while (cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            if (pre->next == cur)
            {
                pre = pre->next;
            }
            else
            {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};