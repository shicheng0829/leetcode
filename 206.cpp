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
    // 头插法
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = head;
        while (p->next)
        {
            ListNode *mid = p->next;
            ListNode *next = p->next->next;
            mid->next = dummy->next;
            dummy->next = mid;
            p->next = next;
        }
        return dummy->next;
    }
    // 迭代版
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        while (head)
        {
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    // 递归版
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};