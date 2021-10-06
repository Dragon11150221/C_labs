
#include <stdio.h>
#include "insertionsort.h"

void insertionsort(int a[], int left, int right) {

	int i;
	struct node *head;
	struct node *p;

	head = malloc(sizeof(struct node));
	if (head == NULL) {
		printf("Error: malloc failed in insertionsort.c\n");
		exit(1);
	}
	head->value = a[left];
	head->next = NULL;

	for (i = left + 1; i <= right; i++) {
#ifdef RETURN
		head = add_to_list(head, a[i]);
#else
		add_to_list2(&head, a[i]);
#endif
	}
	for (i = left; i <= right; i++) {
		a[i] = head->value;
		p = head;
		head = head->next;
		free(p);
	}

	return;
}

#ifdef RETURN
struct node *add_to_list(struct node *head, int n) {

	struct node *new_node;
	struct node *p, *q;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in insertionsort.c\n");
		exit(1);
	}
	new_node->value = n;

	static int count = 0;
	count++;
	if (head->value > new_node->value) {
		new_node->next = head;
		head = new_node;
		printf("Numbers of comparisons so far: %d\n", count);
		return head;
	}

	p = head;
	q = p->next;
	count++;
	while (q != NULL && q->value <= n) {
		count++;
		p = q;
		q = p->next;
	}
	if (q == NULL) count--;

	new_node->next = q;
	p->next = new_node;

	printf("Numbers of comparisons so far: %d\n", count);
	return head;
}

#else

void add_to_list2(struct node **head, int n) {

	struct node *new_node;
	struct node *p, *q;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in insertionsort.c\n");
		exit(1);
	}
	new_node->value = n;

	if ((*head)->value > new_node->value) {
		new_node->next = *head;
		*head = new_node;
		return;
	}

	p = *head;
	q = p->next;
	while (q != NULL && q->value <= n) {
		p = q;
		q = p->next;
	}

	if (q != NULL) {
		new_node->next = q;
		p->next = new_node;
	}
	else {
		new_node->next = NULL;
		p->next = new_node;
	}
	return;
}
#endif
