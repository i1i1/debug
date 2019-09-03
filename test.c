#include <stdio.h>

#include "debug.h"

#define custom_dispatch(arg)			\
	struct foo:	foo_describe(arg),

struct foo {
	int a;
	char *b;
	float c;
};

char *
foo_describe(struct foo a)
{
	static char str[1024];

	snprintf(str, 1024, "{ .a = %d, .b = \"%s\", .c = %f }", a.a, a.b, a.c);

	return str;
}


int
main(void)
{
	struct foo a = { 24, "abcdef", 3.1415926 };
	
	debug(a);
}

