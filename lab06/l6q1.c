/* purposes: lab6 q1
 * Authors: Jinglong Zhao
 * Reference: in README.txt
 * Dates: Started on October 14, 2020
          Last modified on October 15, 2020
*/

#include <stdio.h>
#define N 10

int main() {
    int b[N];
    int *a = &b[0];
    int *p = a, *q = a + N - 1;
    for (int i = N-1; i >= 0 ; i--) {
        *(a + i) = i + 1;
    }

    while (p < q) {
        int temp = *p;
        *p++ = *q;
        *q-- = temp;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
    return 0;
}
