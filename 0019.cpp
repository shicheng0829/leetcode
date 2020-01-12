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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *post = dummy;
        for (int i = 0; i < n; ++i)
            post = post->next;
        while (post->next)
        {
            pre = pre->next;
            post = post->next;
        }
        pre->next = pre->next->next;
        return dummy->next;
    }
};