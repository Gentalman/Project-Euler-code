#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20
#define REGION 3

int main()
{
	int nc, i, j, k;
    unsigned long long int max_sum = 0, sum;
	char c, num[MAX_LENGTH][MAX_LENGTH];
	unsigned int digit = 0;

    FILE *fp = NULL;
    if(NULL == (fp = fopen("numlist.txt", "r")))
    {
	    printf("open file error\n");
        while(1);
    }

	i = j = 0;
	while ((c = fgetc(fp)) != EOF) {
		if (c <= '9' && c >= '0') {
		    digit = digit * 10 + (c - '0');
		}
		else if (c == ' ') {
			num[i][j] = digit;
		    j++;
			digit = 0;
		    continue;
		}
		else if (c == '\n') {
			num[i][j] = digit;
		    i++;
			j = 0;
			digit = 0;
		    continue;
		}
		else {
		    break;
		}
    }
	num[i][j] = digit;

	for (i = 0; i < MAX_LENGTH; i++) {
		for (j = 0; j < MAX_LENGTH; j++) {
	        printf("%2d ", num[i][j]);
		}
	    printf("\n");
	}

	for (i = 0; i < MAX_LENGTH; i++) {
		for (j = 0; j < MAX_LENGTH; j++) {
	        if (j < MAX_LENGTH-REGION)
            {
                sum = num[i][j] * num[i][j+1] * num[i][j+2] * num[i][j+3];
            }
 			if (sum > max_sum) {
			   max_sum = sum;
			}

	        if (i < MAX_LENGTH-REGION)
            {
                sum = num[i][j] * num[i+1][j] * num[i+2][j] * num[i+3][j];
            }
 			if (sum > max_sum) {
			   max_sum = sum;
			}

	        if ( (i < MAX_LENGTH-REGION) && (j < MAX_LENGTH-REGION) )
            {
                sum = num[i][j] * num[i+1][j+1] * num[i+2][j+2] * num[i+3][j+3];
            }
 			if (sum > max_sum) {
			   max_sum = sum;
			}

	        if ( (i < MAX_LENGTH-REGION) && (j > REGION) )
            {
                sum = num[i][j] * num[i+1][j-1] * num[i+2][j-2] * num[i+3][j-3];
            }
 			if (sum > max_sum) {
			   max_sum = sum;
			}
		}
	}

 /*	for (i = 0; i < MAX_LENGTH; i++) {
		for (j = 0; j < MAX_LENGTH; j++) {
	        sum = num[i][j % MAX_LENGTH] * num[i][(j+1) % MAX_LENGTH] * num[i][(j+2) % MAX_LENGTH] * num[i][(j+3) % MAX_LENGTH];
			if (sum > max_sum) {
			   max_sum = sum;
			   printf("%d %d %d %d %d\n", num[i][j % MAX_LENGTH], num[i][(j+1) % MAX_LENGTH], num[i][(j+2) % MAX_LENGTH], num[i][(j+3) % MAX_LENGTH], max_sum);
			}
		}
	}

 	for (j = 0; j < MAX_LENGTH; j++) {
		for (i = 0; i < MAX_LENGTH; i++) {
	        sum = num[i % MAX_LENGTH][j] * num[(i+1) % MAX_LENGTH][j] * num[(i+2) % MAX_LENGTH][j] * num[(i+3) % MAX_LENGTH][j];
			if (sum > max_sum) {
			   max_sum = sum;
			   printf("%d %d %d %d %d\n", num[i % MAX_LENGTH][j], num[(i+1) % MAX_LENGTH][j], num[(i+2) % MAX_LENGTH][j], num[(i+3) % MAX_LENGTH][j], max_sum);
			}
		}
	}

 	for (j = 0; j < MAX_LENGTH - REGION; j++) {
		k = j;
		for (i = 0; j < MAX_LENGTH; i++, j++) {
	        sum = num[i][j] * num[(i+1) % (MAX_LENGTH-k)][(j+1) % (MAX_LENGTH-k)] * num[(i+2) % (MAX_LENGTH-k)][(j+2) % (MAX_LENGTH-k)] * num[(i+3) % (MAX_LENGTH-k)][(j+3) % (MAX_LENGTH-k)];
			if (sum > max_sum) {
			   max_sum = sum;
			}
		}
		j = k;
	}

 	for (i = 1; i < MAX_LENGTH - REGION; i++) {
		k = i;
		for (j = 0; i < MAX_LENGTH; i++, j++) {
	        sum = num[i][j] * num[(i+1) % (MAX_LENGTH-k)][(j+1) % (MAX_LENGTH-k)] * num[(i+2) % (MAX_LENGTH-k)][(j+2) % (MAX_LENGTH-k)] * num[(i+3) % (MAX_LENGTH-k)][(j+3) % (MAX_LENGTH-k)];
			if (sum > max_sum) {
			   max_sum = sum;
			}
		}
		i = k;
	}

 	for (i = MAX_LENGTH - 1; i >= REGION; i--) {
		for (j = 0; i >= REGION; i--, j++) {
	        sum = num[i][j] * num[i-1][j+1] * num[i-2][j+2] * num[i-3][j+3];
			if (sum > max_sum) {
			   max_sum = sum;
			}
		}
	}

 	for (j = 1; j < MAX_LENGTH - REGION; j++) {
		for (i = MAX_LENGTH - 1; j < MAX_LENGTH - REGION; i--, j++) {
	        sum = num[i][j] * num[i-1][j+1] * num[i-2][j+2] * num[i-3][j+3];
			if (sum > max_sum) {
			   max_sum = sum;
			}
		}
	}  */

	printf("%lld\n", max_sum);

    return 0;
}
