#include <stdio.h>
#include <stdlib.h>

char num[10000];

int main()
{
    int array_index = 0;
    int i, j, temp;
    unsigned int sum = 0;

    num[0] = 2;
    for (i = 1; i < 10000; i++)
    {
        for (j = array_index; j>= 0; j--)
        {
            temp = num[j]*2;
            if (temp >= 10)
            {
                num[j] = temp%10;
                num[j+1] += temp/10;
                if (j == array_index)
                    array_index++;
            }
            else
            {
                num[j] = temp;
            }
        }
    }

    for (i = array_index; i >= 0; i--)
    {
        sum += num[i];
    }
    printf("sum is %d", sum);

    return 0;
}
