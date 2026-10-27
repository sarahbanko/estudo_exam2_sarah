#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
        i++;
    while (str[i])
    {
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        count++;
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
    }
    return (count);
}

void split_free(char **array, int word)
{
    int i;

    i = 0;
    while (i < word)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

char **ft_split(char *str)
{
    int i;
    int start;
    int end;
    char **array;
    int count;
    int word;
    int j;

    count = count_words(str);
    array = malloc(sizeof(char *) * (count + 1));
    if (!array)
        return NULL;
    i = 0;
    word = 0;
    while (word < count)
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        start = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        end = i;
        array[word] = malloc(sizeof(char) * (end - start + 1));
        if (!array[word])
        {
            split_free(array, word);
            return NULL;
        }
        j = 0;
        while (start < end)
        {
            array[word][j] = str[start];
            j++;
            start++;
        }
        array[word][j] = '\0';
        word++;
    }
    array[word] = NULL;
    return (array);
}

int main()
{
    char **result;
    int i;

    i = 0;
    result = ft_split("Meu nome é sarah Banko");
    while (result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    free(result);
    return (0);
}