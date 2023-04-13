#include <stdio.h>

double sum(int n)
{
	if (n == 1)
		return 1;
	return (double)1 / n + sum(n - 1);
}