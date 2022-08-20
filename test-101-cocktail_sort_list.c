#include "sort.h"
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
	int IS_SWAPPED = 1;
	char *best_case = "O(n)", *average_case = "O(n^2)";
	char *worst_case = "O(n^2)";
	listint_t **head = (listint_t **) list,
	**left = (listint_t **) malloc(sizeof(listint_t)),
	**right = (listint_t **) malloc(sizeof(listint_t)),
	*curr = NULL, *temp = NULL;
	FILE *fp = fopen("101-O", "w");

	if (fp == NULL || list == NULL || *head == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	*right = *left = *head;
	while ((*right)->next != NULL)
		*right = (*right)->next;

	fprintf(stdout, "<-- CHECK head is left -->> %s\n",
	*head == *left ? "True" : "False");
	fprintf(stdout, "<-- CHECK head is greater than right -->> %s\n",
	*head > *right ? "True" : "False");
	fprintf(stdout, "<-- CHECK left is greater than right -->> %s\n\n",
	*left > *right ? "True" : "False");
	fprintf(stdout, "<--- HEAD --->> %p\n", (void *)*head);
	print_list(*head);
	fprintf(stdout, "<--- right --->> %p\n", (void *)*right);
	print_list(*right);
	fprintf(stdout, "<--- left --->> %p\n", (void *)*left);
	print_list(*left);

	while ((*left) >= (*right) && IS_SWAPPED)
	{
		IS_SWAPPED = 0;
		fprintf(stdout, "\n<--- Start Traversing Forward/right --->> %p\n", (void *)*left);
		for (curr = (*left); curr != NULL && curr >= (*right); 
				curr = curr->next)
		{
			temp = curr->next;
			fprintf(stdout, "curr :=> %p\t", (void *)curr);
			fprintf(stdout, "curr->n :=> %d\n",
					(int)curr->n);
			if (temp != NULL && curr->n > temp->n)
			{
				fprintf(stdout, "temp :=> %p\t", (void *)temp);
				fprintf(stdout, "temp->n :=> %d\n",
					(int)temp->n);

				if (curr->prev != NULL)
					curr->prev->next = temp;
				temp->prev = curr->prev;
				if (temp->next != NULL)
					temp->next->prev = curr;
				curr->next = temp->next;
				curr->prev = temp;
				temp->next = curr;
				if (temp->prev == NULL)
					*head = temp;
				IS_SWAPPED = 1;
				curr = temp;
				print_list(*head);
			}
			if (curr->next == NULL)
				*right = curr;
		}
		fprintf(stdout, "<---Finish Traversing Forward/right--->> %p\n",
			(void *)*left);
		*right = (*right)->prev;
		fprintf(stdout, "\n<---Start Traversing Backward/left-->> %p\n",
			(void *)*right);
		if (IS_SWAPPED)
		{
			IS_SWAPPED = 0;
			for (curr = (*right); curr != NULL && curr <= (*left);
					curr = curr->prev)
			{
				temp = curr->prev;
				fprintf(stdout, "curr :=> %p\t", 
					(void *)curr);
				fprintf(stdout, "curr->n :=> %d\n",
					(int)curr->n);
				if (temp != NULL && curr->n < temp->n)
				{
					fprintf(stdout, "temp :=> %p\t",
						(void *)temp);
					fprintf(stdout, "temp->n :=> %d\n",
						(int)temp->n);

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
				fprintf(stdout, "(*left) :=> %p\t", 
					(void *)(*left));
				fprintf(stdout, "(*left)->n :=> %d\n",
					(int)(*left)->n);
				fprintf(stdout, "Finally here!\n");
			}
		}
		fprintf(stdout, "<--- Finish Traversing Backward/left-->> %p\n",
			(void *)*right);
		*left = (*left)->next;
	}
	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	free(left);
	free(right);
	fclose(fp);
}