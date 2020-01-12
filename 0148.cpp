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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode *p1 = sortList(head);
        ListNode *p2 = sortList(slow);
        return merge(p1, p2);
    }
    ListNode *merge(ListNode *p1, ListNode *p2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                cur->next = p1;
                cur = cur->next;
                p1 = p1->next;
            }
            else
            {
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
            }
        }
        if (p1)
            cur->next = p1;
        if (p2)
            cur->next = p2;
        return dummy->next;
    }
};