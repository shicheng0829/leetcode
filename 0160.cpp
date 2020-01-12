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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1 = len(headA);
        int l2 = len(headB);
        if (l1 < l2)
        {
            swap(headA, headB);
            swap(l1, l2);
        }
        int step = l1 - l2;
        for (int i = 0; i < step; ++i)
        {
            headA = headA->next;
        }
        while (1)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
    int len(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            head = head->next;
            ++count;
        }
        return count;
    }
};