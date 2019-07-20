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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *left, ListNode *right) { return left->val > right->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
                pq.push(lists[i]);
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (!pq.empty())
        {
            ListNode *minNode = pq.top();
            cur->next = minNode;
            cur = cur->next;
            if (minNode->next)
                pq.push(minNode->next);
            pq.pop();
        }
        return dummy->next;
    }
};