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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *pre = nullptr;
        while (slow)
        {
            ListNode *next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        while (head && pre)
        {
            if (head->val != pre->val)
                return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};