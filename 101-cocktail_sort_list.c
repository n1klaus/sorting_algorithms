#include "sort.h"
/**
 * traverse_forward - traverses the list from @left to @right
 * while shifting the largest element to the @right
 * @head : head node of the doubly linked list
 * @left : left-most node of the doubly linked list
 * @right : right-most node of the doubly linked list
 *
 * Return: 0 if successfull, otherwise 1
 */
int traverse_forward(listint_t **head, listint_t **left, listint_t **right)
{
	int IS_SWAPPED = 0;
	listint_t *curr = NULL, *temp = NULL;

	if (*head == NULL || *left == NULL || *right == NULL)
		return (EXIT_FAILURE);
	for (curr = (*left); curr != NULL && curr >= (*right);
			curr = curr->next)
	{
		temp = curr->next;
		if (temp != NULL && curr->n > temp->n)
		{
			if (curr->prev != NULL)
				curr->prev->next = temp;
			temp->prev = curr->prev;
			if (temp->next != NULL)
				temp->next->prev = curr;
			curr->next = temp->next;
			curr->prev = temp;
			temp->next = curr;
			IS_SWAPPED = 1;
			if (temp->prev == NULL)
				*head = temp;
			curr = temp;
			print_list(*head);
		}
		if (curr->next == NULL)
			*right = curr;
	}
	if (!IS_SWAPPED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * traverse_backward - traverses the list from @right to @left
 * while shifting the smallest element to the @left
 * @head : head node of the doubly linked list
 * @left : left-most node of the doubly linked list
 * @right : right-most node of the doubly linked list
 *
 * Return: 0 if successfull, otherwise 1
 */
int traverse_backward(listint_t **head, listint_t **right, listint_t **left)
{
	int IS_SWAPPED = 0;
	listint_t *curr = NULL, *temp = NULL;

	if (*head == NULL || *left == NULL || *right == NULL)
		return (EXIT_FAILURE);
	for (curr = (*right); curr != NULL && curr <= (*left);
			curr = curr->prev)
	{
		temp = curr->prev;
		if (temp != NULL && curr->n < temp->n)
		{
			if (curr->next != NULL)
				curr->next->prev = temp;
			temp->next = curr->next;
			if (temp->prev != NULL)
				temp->prev->next = curr;
			curr->prev = temp->prev;
			temp->prev = curr;
			curr->next = temp;
			IS_SWAPPED = 1;
			if (curr->prev == NULL)
				*head = curr;
			curr = temp;
			print_list(*head);
		}
		if (curr->prev == NULL)
			*left = curr;
	}
	if (!IS_SWAPPED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * cocktail_sort_list - in-place comparison sorting algorithm for
 * repeatedly passing through the list from left to right
 * shifting the largest element at the end and then
 * passing from right to left shiting the smallest element at the beginning
 * @list : doubly linked list of elements
 *
 * Return : Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int IS_SWAPPED = 1, result = 0;
	char *best_case = "O(n)", *average_case = "O(n^2)";
	char *worst_case = "O(n^2)";
	listint_t **head = (listint_t **) list,
	**left = (listint_t **) malloc(sizeof(listint_t)),
	**right = (listint_t **) malloc(sizeof(listint_t));
	FILE *fp = fopen("101-O", "w");

	if (fp == NULL || list == NULL || *head == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	*right = *left = *head;
	while ((*right)->next != NULL)
		*right = (*right)->next;

	while ((*left) >= (*right) && IS_SWAPPED)
	{
		IS_SWAPPED = 0;
		result = traverse_forward(head, left, right);
		if (!result)
			IS_SWAPPED = 1;
		*right = (*right)->prev;
		if (IS_SWAPPED)
		{
			IS_SWAPPED = 0;
			result = traverse_backward(head, right, left);
			if (!result)
				IS_SWAPPED = 1;
		}
		*left = (*left)->next;
	}
	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	free(left);
	free(right);
	fclose(fp);
}
