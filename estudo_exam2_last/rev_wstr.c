#include <unistd.h>

int count_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i])
        {
            count++;
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                i++;
        }
    }
    return (count);
}
void print_rev(char *str)
{
    int count_w;
    int i;
    int start;
    int end;

    i = 0;
    count_w = count_words(str);
    if (count_w == 1)
    {
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        return ;
    }
    else if (count_w > 1)
    {
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
            if (i >= 0)
                write(1, " ", 1);
            while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
                i--;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_rev(argv[1]);
    write(1, "\n", 1);
    return (0);
}