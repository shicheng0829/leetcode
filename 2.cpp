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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        int next = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int cur = val1 + val2 + next;
            next = cur / 10;
            cur %= 10;
            p->next = new ListNode(cur);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if (next)
            p->next = new ListNode(next);
        return res->next;
    }
};