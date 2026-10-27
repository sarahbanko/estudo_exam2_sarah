#include <stdio.h>
#include <stdlib.h>

int pgcd(int n1, int n2)
{
    int max;
    int i;

    max = 1;
    i = 1;
    while (i <= n1 && i <= n2)
    {
        if (n1 % i == 0 && n2 % i == 0)
            max = i;
        i++;
    }
    return (max);
}

int main(int argc, char **argv)
{
    int n1;
    int n2;
    int result;
    
    if (argc == 3)
    {
        n1 = atoi(argv[1]);
        n2 = atoi(argv[2]);
        result = pgcd(n1, n2);
        printf("%d", result);
    }
    printf("\n");
    return (0);
}