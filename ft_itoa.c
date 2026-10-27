#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int count_nbr(long nbr)
{
    int count;

    count = 0;
    if (nbr <= 0)
        count++;
    while (nbr)
    {
        nbr /= 10;
        count++;
    }
    return (count);
}

char	*ft_itoa(int nbr)
{
    long n;
    int count_dig;
    char *result;

    n = nbr;
    count_dig = count_nbr(n);
    result = malloc(sizeof(char) * (count_dig + 1));
    if (!result)
        return NULL;
    result[count_dig] = '\0';
    if (n < 0)
    {
        result[0] = '-';
        n = - n;
    }
    if (n == 0)
        result[0] = '0';
    while (n)
    {
        count_dig--;
        result[count_dig] = n % 10 + '0';
        n /= 10;
    }
    return (result);
}