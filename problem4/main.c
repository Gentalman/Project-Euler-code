#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool isPalindrome(int num);

    int i, j;
    int large_pal = 0;
    int k, l;

    for (i = 999; i > 100; i--) {
        for (j = i; j > 100; j--) {
            if (isPalindrome(i*j))
                if (i*j > large_pal) {
                    large_pal = i*j;
                    k = i;
                    l = j;
                }
        }
    }

    printf("k is %d\n", k);
    printf("l is %d\n", l);
    printf("palindrome is %d\n", large_pal);

    return 0;
}

bool isPalindrome(int num)
{
    int end = 0;
    int origin = num;

    while (num) {
        end *= 10;
        end += num % 10;
        num /= 10;
    }

    return (origin == end);
}
