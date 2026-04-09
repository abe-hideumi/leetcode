/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k == 1)
        return (head);

    struct ListNode *cur = head;
    int *hv[k / 2];
    int k_size = k / 2;

    while (cur != NULL)
    {
        struct ListNode *tmp = cur;
        for (int i = 0; i < k - 1; i++)
        {
            tmp = tmp->next;
            if (tmp == NULL)
                return (head);
        }   
        for (int i = 0; i < k_size && cur != NULL; i++)
        {
            hv[i] = &cur->val;
            cur = cur->next;
        }
        if (k % 2 == 1  && cur != NULL)
            cur = cur->next;
        for (int i = 1; i <= k_size; i++)
        {
            int t = *hv[k_size - i];
            *hv[k_size - i] = cur->val;
            cur->val = t;
            cur = cur->next;
        }
    }
    return (head);
}