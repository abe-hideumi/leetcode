/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *cur;
    int tmp;

    if (head == NULL)
        return (head);
    cur = head;
    while (cur != NULL)
    {
        tmp = cur->val;
        if (cur->next == NULL)
            break ;
        cur->val = cur->next->val;
        cur = cur->next;
        cur->val = tmp;
        if (cur->next == NULL)
            break ;
        cur = cur->next;
    }
    return (head);
}