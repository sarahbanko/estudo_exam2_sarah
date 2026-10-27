#include <unistd.h>

void print_ind(char c, int ind)
{
    int i;

    i = 0;
    while (i < ind)
    {
        write(1, &c, 1);
        i++;
    }
}

void repeat_alpha(char *str)
{
    int i;
    int count;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            count = str[i] - 'a' + 1;
            print_ind(str[i], count);
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            count = str[i] - 'A' + 1;
            print_ind(str[i], count);
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}
int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    write(1, "\n", 1);
}