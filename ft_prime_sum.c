#include <unistd.h>

void putnbr(int nbr)
{
    char c;
    if (nbr >= 10)
        putnbr(nbr/10);
    c = (nbr % 10) + '0';
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int i;
    int nbr;

    i = 0;
    nbr = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        nbr = (nbr * 10) + (str[i] - '0');
        i++;
    }
    return (nbr);
}

int prime_sum(int nbr)
{
    int count;
    int div;
    int sum;
    int n;

    sum = 0;
    n = 2;
    while (n <= nbr)
    {
        div = 1;
        count = 0;
        while (div <= n)
        {
            if (n % div == 0)
                count++;
            div++;
        }
        if (count == 2)
            sum += n;
        n++;
    }
}

int main(int argc, char **argv)
{
    int number;

    if (argc == 2)
    {
        number = ft_atoi(argv[1]);
        if (number < 0)
            write(1, "0", 1);
        else
            putnbr(prime_sum(number));
    }
    write(1, "\n", 1);
    return (0);

}