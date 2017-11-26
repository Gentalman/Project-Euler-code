#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int square_sum = 0, sum_square = 0, sum = 0;
    unsigned char i;

    for (i = 1; i <= 100; i++) {
        sum_square += i*i;
        sum += i;
    }
    square_sum = sum*sum;

    printf("sum_square is %u\n", sum_square);
    printf("square_sum is %u\n", square_sum);
    printf("the difference between the square_sum and the sum_square is %u\n", square_sum-sum_square);

    return 0;
}
