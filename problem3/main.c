#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int i, j;
    int limit = 1000000;
    long long num = 600851475143;

    for (i = 2; i < limit; i++) {
        for (j = 2; j <= i; j++) {
            if (j == i) {
                while ((num % j) == 0) {
                    printf("prime num is %d ,", i);
                    num /= j;
                    printf("num now is %lld\n", num);
                    if (num == 1) {
                        printf("the large prime num is %d\n", i);
                        return 0;
                    }
                }
            }
            if (i % j == 0) {
                break;
            }
        }
    }

    return 0;
}
