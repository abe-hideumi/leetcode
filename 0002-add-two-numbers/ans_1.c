
struct ListNode
{
	int				ft_val;
	struct ListNode	*ft_next;
};


int	list_num(struct ListNode *list)
{
	int	total;
	int	count;

	total = 0;
	count = 1;
	while (list != NULL)
	{
		if (count == 1)
			total += list->val;
		else
			total = (list->val * count) + total;
		list = list->next;
		count *= 10;
	}
	return (total);
}

int	ft_list_size(int total)
{
	int	count;

	count = 0;
	while (total > 0)
	{
		total = total / 10;
		count++;
	}
	return (count);
}

void	list_in_num(struct ListNode *result, int total)
{
	struct ListNode	*tmp;

	tmp = result;
	while (total > 0)
	{
		tmp->val = total % 10;
		total = total / 10;
		if (total > 0)
		{
			tmp->next = malloc(sizeof(struct ListNode));
			tmp = tmp->next;
			tmp->val = 0;
			tmp->next = NULL;
		}
	}
}

struct ListNode*	addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode	*result;
	int				l1_num;
	int				l2_num;
	int				total;

	l1_num = list_num(l1);
	l2_num = list_num(l2);
	total = l1_num + l2_num;
	result = malloc(sizeof(struct ListNode));
	if (result == NULL)
		return (NULL);
	result->val = 0;
	result->next = 0;
	list_in_num(result, total);
	return (result);
}