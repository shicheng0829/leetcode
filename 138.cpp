/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        copy(head);
        random(head);
        Node *newHead = split(head);
        return newHead;
    }
    Node *copy(Node *head)
    {
        Node *cur = head;
        while (cur)
        {
            Node *next = cur->next;
            cur->next = new Node(cur->val, next, nullptr);
            cur = next;
        }
        return head;
    }
    Node *random(Node *head)
    {
        Node *cur = head;
        while (cur)
        {
            Node *next = cur->next;
            if (cur->random)
                next->random = cur->random->next;
            else
                next->random = nullptr;
            cur = next->next;
        }
        return head;
    }
    Node *split(Node *head)
    {
        Node *cur = head;
        Node *newcur = head->next;
        Node *newHead = head->next;
        while (cur && newcur)
        {
            cur->next = newcur->next;
            if (cur->next)
                newcur->next = cur->next->next;
            cur = cur->next;
            newcur = newcur->next;
        }
        return newHead;
    }
};