#include <stdlib.h>
#include <stdio.h>

int count_digits(long nbr)
{
    int count;

    count = 0;
    if (nbr <= 0)
        count++;
    while (nbr)
    {
        count++;
        nbr /= 10;
    }
    return (count);
}
char	*ft_itoa(int nbr)
{
    long n;
    char *array;
    int len;

    n = nbr;
    len = count_digits(n);
    array = malloc(sizeof(char) * (len + 1));
    if (!array)
        return NULL;
    array[len] = '\0';
    if (n < 0)
    {
        array[0] = '-';
        n = - n;
    }
    if (n == 0)
        array[0] = '0';
    while (n)
    {
        len--;
        array[len] = n % 10 + '0';
        n /= 10;
    }
    return (array);
}

int main()
{
    char *result;

    result = ft_itoa(-2147483648);
    printf("%s\n", result);
    return (0);
}