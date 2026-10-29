#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    unsigned int j;
    int temp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int tab[] = {5, 1, 8, 2, 0};
    int i;

    i = 0;
    sort_int_tab(tab, 5);
    while (i < 5)
    {
        printf("%d", tab[i]);
        i++;
    }
    return (0);
}