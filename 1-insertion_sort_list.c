#include "sort.h"
/**
 * insertion_sort_list - in-place sorting algorithm for moving
 * smaller integer numbers in @list in correct positions
 * in the sorted list, while shifting larger numbers to make space
 * @list : doubly linked list of elements
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	char *best_case = "n", *average_case = "n * n", *worst_case = "n * n";
	listint_t **head = (listint_t **)list;
	listint_t *temp = NULL;
	listint_t *curr = (listint_t *)(*head)->next;
	FILE *fp = fopen("1-O", "w");

	if (fp == NULL || list == NULL || *head == NULL)
		exit(EXIT_FAILURE);
	while (curr != NULL)
	{
		temp = curr->prev;
		while (temp != NULL)
		{
			if (curr->n < temp->n)
			{
				if (temp->prev != NULL)
					temp->prev->next = curr;
				curr->prev = temp->prev;
				if (curr->next != NULL)
					curr->next->prev = temp;
				temp->next = curr->next;
				temp->prev = curr;
				curr->next = temp;
				if (curr->prev == NULL)
					*head = curr;
				print_list(*head);
			}
			else
				break;
			temp = curr->prev;
		}
		curr = curr->next;
	}
	fprintf(fp, "O(%s)\nO(%s)\nO(%s)\n", best_case, average_case,
		worst_case);
	free(temp);
	free(curr);
	fclose(fp);
}
