#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long int num = 0, divisor = 0, capped;
	int factor_count = 0;
	unsigned long long int i = 0;

	for (i = 1; factor_count <= 500; i++)
	{
	    num += i;
		capped = sqrt((double)num);
		factor_count = 2;
		for (divisor = 2; divisor <= capped; divisor++)
		{
		   if (num%divisor == 0)
			   factor_count += 2;
		}
	}
	printf("num is %lld", num);

    return 0;
}
