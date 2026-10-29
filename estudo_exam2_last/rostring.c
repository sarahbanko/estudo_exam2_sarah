#include <unistd.h>

void rostring(char *str)
{
    int i;
    int start;
    int end;

    i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    start = i;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    end = i;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i])
        {
            while (str[i] && str[i] != ' ' && str[i] != '\t')
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
        }

    }
    while (start < end)
    {
        write(1, &str[start], 1);
        start++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
        rostring(argv[1]);
    write(1, "\n", 1);
    return (0);
}