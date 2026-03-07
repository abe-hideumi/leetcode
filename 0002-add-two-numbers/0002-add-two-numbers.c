/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// list_size: リストの長さを取得する
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

// リストのvalを配列にする
// 配列の後ろから、リストの先頭valを入れていく
// 2->3->4 の時は [4][3][2]にして返す
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

// 配列の後ろからtmpに足していく
// result->valには　tmp % 10を入れて1の位を格納
// tmp /= 10 は　１の位を足した時に繰り上がりがある時、繰り上がり分だけにする
// l1, l2のサイズがまだ残っている || 繰り上がりがある場合はlist->nextをmallocし確保
struct ListNode* list_sum(int *l1, int l1_s, int *l2, int l2_s)
{
	int	tmp;
	struct ListNode	*sum;
    struct ListNode *head;

	tmp = 0;
	sum = malloc(sizeof(struct ListNode));
	if (sum == NULL)
		return (NULL);
	sum->val = 0;
	sum->next = NULL;
    head = sum;
	while (1)
    {
        l1_s--;
        l2_s--;
        if (l1_s >= 0)
            tmp += l1[l1_s];
        if (l2_s >= 0)
            tmp += l2[l2_s];
        sum->val = tmp % 10;
        tmp /= 10;
        if (l1_s > 0 || l2_s > 0 || tmp > 0)
        {
            sum->next = malloc(sizeof(struct ListNode));
            if (sum->next == NULL)
                return (NULL);
            sum = sum->next;
            sum->val = 0;
            sum->next = NULL;
        }
        else
            break ;
    }
	return (head);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int l1_size = list_size(l1);
    int *l1_a = array(l1, l1_size);
    int l2_size = list_size(l2);
    int *l2_a = array(l2, l2_size);
    int tmp;
    struct ListNode *result;

    result = list_sum(l1_a, l1_size, l2_a, l2_size);
    if (result == NULL)
		return (NULL);
    free(l1_a);
    free(l2_a);
    return (result);
}