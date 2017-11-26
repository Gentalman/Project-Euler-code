#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define REGION 13

int main()
{
	int nc, i, j;
    unsigned long long int max_sum = 0, sum;
	char c, num[MAX_LENGTH];

    FILE *fp = NULL;
    if(NULL == (fp = fopen("numlist.txt", "r")))
    {
	    printf("open file error\n");
        while(1);
    }

	nc = 0;
	while ((c = fgetc(fp)) != EOF) {
		if (c <= '9' && c >= '0') {
		    num[nc] = c - '0';
			nc++;
		}
		else if (c == '\n') {
		    continue;
		}
		else {
		    break;
		}
    }

	for (i = 0; i < nc; i++) {
	    printf("%d ", num[i]);
	}

	printf("%ld\n", nc);

	for (i = 0; i < nc-REGION+1; i++) {
		sum = 1;
		for (j = i; j < i+REGION; j++) {
			if (num[j] == 0) {
			    i = j;
				break;
			}
		    sum *= num[j];
		}
		if (sum > max_sum) {
		   max_sum = sum;
		}
	}

	printf("%lld\n", max_sum);

    return 0;
}
