#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_LENGTH 1000000

unsigned int prime_array[MAX_LENGTH];

//质数的倍数不是质数，所以一个数如果不能被小于它的开平方的质数整除，那他也是质数
bool is_prime(int num)
{
    unsigned int i, cycle_count;
    static unsigned int index = 1;

    cycle_count = sqrt(num);
    for (i = 0; prime_array[i] <= cycle_count; i++) {
        if (num % prime_array[i] == 0)
            return false;
    }
    prime_array[index++] = num;

    return true;
}

int main()
{
    clock_t start, finish;
    int count = 0;
    unsigned int num = 1;
    prime_array[0] = 2;

    start = clock();

    while (count != 1000000) {
        num += 2;   //2的倍数都是偶数
        if (is_prime(num)) {
            count++;
        }
    }
    printf("%d ", num);

    finish = clock();
    printf("cost %f second\n", (double)(finish-start) / CLOCKS_PER_SEC);

    return 0;
}
