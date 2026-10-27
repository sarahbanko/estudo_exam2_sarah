#include <unistd.h>
#include <stdlib.h>

void print_rev(char *str)
{
    int i;
    int start;
    int end;

    i = 0;
    while (str[i])
        i++;
    i--;
    while (i >= 0)
    {
        end = i;
        while (i >= 0 && str[i] != ' ' && str[i] != '\t')
            i--;
        start = i + 1;
        while (start <= end)
        {
            write(1, &str[start], 1);
            start++;
        }
        while (i >= 0 && (str[i] == ' ' || str[i]== '\t'))
            i--;
        if (i >= 0)
            write(1, " ", 1);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_rev(argv[1]);
    write(1, "\n", 1);
    return (0);
}