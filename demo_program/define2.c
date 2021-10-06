
#include "define2.h"

IDENT(foo)

PRAGMA(data(heap_size >= 10000))

int main() {

	int i = 1, j = 2;
	float x = 3, y = 4;

#ifdef DEBUG

	printf("DOUBLE(%f) = %f\n", x, DOUBLE(x));
	PRINT_INT(1/2);

GENERIC_MAX(float)
	printf("max(%f, %f) is %f\n", x, y, float_max(x, y));
GENERIC_MAX(int)
	printf("max(%d, %d) is %d\n", i+1, j+2, int_max(i+1, j+2));

#undef DOUBLE
#define DOUBLE(x) (3*(x))
	printf("DOUBLE(%f) = %f\n", x, DOUBLE(x));

	printf("Date of compilation is '%s'\n", __DATE__ ", " __TIME__);
	printf("Currently inside function '%s'\n", __func__);
	printf("c99? = %d\n", __STDC__);
#endif

	return 0;
}
