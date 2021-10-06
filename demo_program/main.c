
/* sorting: main function
 *
 */

#include <stdio.h>
#include "insertionsort.h" // or "insertionsort_list.h"

int main() {
	int i, n;

	printf("Enter the length of the array: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d integers to be sorted: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	insertionsort(a, 0, n-1);

	printf("In sorted non-decreasing order:");
	for (i = 0; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
