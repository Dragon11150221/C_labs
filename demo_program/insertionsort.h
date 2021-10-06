
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

void insertionsort(int a[], int left, int right);

#ifdef RETURN
struct node *add_to_list(struct node *head, int n);
#else
void add_to_list2(struct node **head, int n);
#endif
