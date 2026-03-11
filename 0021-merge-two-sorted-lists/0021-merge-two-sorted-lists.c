/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool num_comp(struct ListNode *l1, struct ListNode *l2)
{
    return (l1->val <= l2->val);
}

struct ListNode *sort_join_list(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = NULL;
    struct ListNode *tmp = NULL;

    if (num_comp(l1, l2) != 0)
    {
        head = l1;
        l1 = l1->next;
    }
    else 
    {
        head = l2;
        l2 = l2->next;
    }
    tmp = head;
    while(l1 != NULL && l2 != NULL)
    {
        if (num_comp(l1, l2) != 0)
        {
            tmp->next = l1;
            l1 = l1->next; 
        }
        else
        {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    if (l1 != NULL)
        tmp->next = l1;
    else 
        tmp->next = l2;
    return (head);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *result;

    if (list1 == NULL && list2 == NULL)
        return (NULL);
    else if (list1 == NULL)
        return (list2);
    else if (list2 == NULL)
        return (list1);
    result = sort_join_list(list1, list2);
    return (result);
}