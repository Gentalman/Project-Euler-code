#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_LENGTH 1000000

unsigned int prime_array[MAX_LENGTH];

//�����ı�����������������һ����������ܱ�С�����Ŀ�ƽ������������������Ҳ������
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
        num += 2;   //2�ı�������ż��
        if (is_prime(num)) {
            count++;
        }
    }
    printf("%d ", num);

    finish = clock();
    printf("cost %f second\n", (double)(finish-start) / CLOCKS_PER_SEC);

    return 0;
}
