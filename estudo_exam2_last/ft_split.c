#include <stdlib.h>
#include <stdio.h>

int count_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i])
        {
            count++;
            while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
                i++;
        }
    }
    return (count);
}

void free_split(char **array, int word)
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
    int j;
    int word;
    char **array;
    int count_w;
    int start;
    int end;

    count_w = count_words(str);
    array = malloc(sizeof(char *) * (count_w + 1));
    if (!array)
        return NULL;
    i = 0;
    word = 0;
    while (word < count_w)
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
            free_split(array, word);
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
    int word;

    result = ft_split(".    Oi Sarah Banko.   ");
    word = count_words(".    Oi Sarah Banko.   ");
    printf("%d\n", word);
    i = 0;
    while (result[i])
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}