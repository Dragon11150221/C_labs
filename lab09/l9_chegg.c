#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    float x;
    float y;
    struct point *next;
};

struct point *generate (int n) {
    int i;
    struct point *first = NULL, *last = NULL;

    for (i = 0; i < n; i++) {
        if (first == NULL) {
            first = calloc (1, sizeof (struct point));
            last = first;
        }
        else {
            last->next = calloc (1, sizeof (struct point));
            last = last->next;
        }
        last->x = (rand () % 100001) / 100.0; // so that we get numbers in range 0 to 1000
        last->y = (rand () % 100001) / 100.0;
        last->next = NULL;
    }
    return (first);
}

struct point *get_member (struct point *s, int which) {
    // Gets the n'th member of the list (as specified by which)
    int i = 0;
    for (i = 0; i < which; i++) {
        if (s->next == NULL) // if we reached the last element, exit loop and return it
            break;
        s = s->next;
    }
    return (s);
}

int find_points_in_shape (struct point *s) {
    int i = 0;
    while (s) {
        i++;
        s = s->next;
    }
    return (i);
}

struct point *index_sample(struct point *shape, int k) {
    struct point *first = NULL, *last = NULL;
    int n;

    n = find_points_in_shape (shape);
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            first = calloc (1, sizeof (struct point));
            last = first;
        }
        else {
            last->next = calloc (1, sizeof (struct point));
            last = last->next;
        }
        struct point *member = get_member (shape, i * n / (k - 1));
        last->x = member->x;
        last->y = member->y;
        last->next = NULL;
    }
    return (first);
}

float sample_distance (struct point *shape1, struct point *shape2, int k) {
    float dist = 0;

    struct point *one = index_sample (shape1, k);
    struct point *two = index_sample (shape2, k);

    for (int i = 0; i < k; i++) {
        dist += sqrt ((one->x - two->x) * (one->x - two->x) + (one->y - two->y) * (one->y - two->y));
    }
    return (dist);
}

void print_shape (struct point *s) {
    while (s != NULL) {
        printf ("(%0.2f, %0.2f) ", s->x, s->y);
        s = s->next;
    }
}

int main()
{
    int a, b, c;
    printf("Enter two integers in [1, 1000]: ");
    scanf ("%d %d", &a, &b);
    struct point *a1 = generate (a);
    struct point *b1 = generate (b);
    printf ("Shape1 with %d points: <", a);
    print_shape (a1);
    printf (">\n");
    printf ("Shape2 with %d points: <", b);
    print_shape (b1);
    printf (">\n");

    printf ("Enter an integer in [2, 1000]:");
    scanf ("%d", &c);
    printf ("%d-sample of Shape1: <", c);
    struct point *k1 = index_sample (a1, c);
    print_shape (k1);
    printf (">\n");
    printf ("%d-sample of Shape2: <", c);
    struct point *k2 = index_sample (b1, c);
    print_shape (k2);
    printf (">\n");

    printf ("The %d-sample distance is: %0.3f", c, sample_distance (k1, k2, c));


    return 0;
}
