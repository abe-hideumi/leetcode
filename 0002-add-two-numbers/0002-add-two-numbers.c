/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int list_size(struct ListNode *list)
{
    int len;

    len = 0;
    while (list != NULL)
    {
        list = list->next;
        len++;
    }
    return (len);
}

int *array(struct ListNode *list, int l_size)
{
    int *l_re;

    l_re=malloc(sizeof(int) * l_size);
    l_size--;
    while (list != NULL)
    {
        l_re[l_size] = list->val;
        l_size--;
        list = list->next;
    }
    return (l_re);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int l1_size = list_size(l1);
    int *l1_a = array(l1, l1_size);
    int l2_size = list_size(l2);
    int *l2_a = array(l2, l2_size);
    int tmp;
    struct ListNode *head;
    struct ListNode *result;

    result = malloc(sizeof(struct ListNode));
    if (result == NULL)
        return (NULL);
    result->val = 0;
    result->next = NULL;
    head = result;
    tmp = 0;
    while (1)
    {
        l1_size--;
        l2_size--;
        if (l1_size >= 0)
            tmp += l1_a[l1_size];
        if (l2_size >= 0)
            tmp += l2_a[l2_size];
        result->val = tmp % 10;
        tmp /= 10;
        if (l1_size > 0 || l2_size > 0 || tmp > 0)
        {
            result->next = malloc(sizeof(struct ListNode));
            result = result->next;
            result->val = 0;
            result->next = NULL;
        }
        else
            break ;
    }
    free(l1_a);
    free(l2_a);
    return (head);
}