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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *odd_dummy = new ListNode(-1);
        ListNode *even_dummy = new ListNode(-1);
        ListNode *cur = head;
        ListNode *odd_cur = odd_dummy;
        ListNode *even_cur = even_dummy;
        bool flag = true;
        while (cur)
        {
            ListNode *next = cur->next;
            if (flag)
            {
                odd_cur->next = cur;
                cur->next = nullptr;
                odd_cur = cur;
            }
            else
            {
                even_cur->next = cur;
                cur->next = nullptr;
                even_cur = cur;
            }
            cur = next;
            flag = !flag;
        }
        odd_cur->next = even_dummy->next;
        return odd_dummy->next;
    }
};