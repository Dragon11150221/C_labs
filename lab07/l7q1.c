#include <stdio.h>

void byte_value(int *);

int main() {
    int n = 1;
    byte_value(&n);

    printf("Enter an integer: ");
    if (scanf("%d", &n) == 1)
        byte_value(&n);

    return 0;
}

void byte_value(int *p) {
    // fill in the body using only pointer variables
    // printout the memory address of the byte and its unsigned char (integer) value
    // one line for each pair, a total of 4 lines
    unsigned char* cp = (unsigned char*)p; // use pointer to point on each byte

    printf("%p \t %u\n",cp,*cp); //print them 
    printf("%p \t %u\n",cp+1,*(cp+1));
    printf("%p \t %u\n",cp+2,*(cp+2));
    printf("%p \t %u\n",cp+3,*(cp+3));
    return;
}
