
#include <stdio.h>
#include <stdlib.h>


#define DOUBLE(x) (2*(x))

#define IS_EVEN(n) n%2 == 0

#define PRINT_INT(n) printf(#n " = %d\n", (n))

#define GENERIC_MAX(type)         \
type type##_max(type x, type y) { \
	return x > y ? x : y;         \
}

#define IDENT(x) PRAGMA(ident #x)

#define PRAGMA(x) _Pragma(#x)
