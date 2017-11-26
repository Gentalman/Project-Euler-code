#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define LIMIT 1000000
unsigned int length[LIMIT];

int main()
{
	clock_t start, finish;
    double  duration;
	unsigned long long int i, num, max_num;
	int chain_length, max_length = 0;
	length[1] = 1;

	start = clock();
	for (i = 2; i < LIMIT; i++)
	{
	    num = i;
		chain_length = 0;
		while (num > i || (length[num] == 0))
		{
			if (num % 2 == 0)
			{
				num = num >> 1;
			}
			else
			{
				num = 3 * num + 1;
			}
		    chain_length++;
		}
		chain_length += length[num];
		length[i] = chain_length;
		if (chain_length > max_length)
		{
		    max_length = chain_length;
			max_num = i;
		}
	}

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "program cost %f seconds\n", duration );

    printf("max length is %d, num is %d\n", max_length, max_num);

    return 0;
}
