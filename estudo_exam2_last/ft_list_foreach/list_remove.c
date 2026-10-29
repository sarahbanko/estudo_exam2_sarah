#include <stdlib.h>
#include "list_remove.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;
    t_list *prev;
    t_list *temp;

    current = *begin_list;
    prev = 0;
    while (current)
    {
        if (cmp(current->data, data_ref) == 0)
        {
            temp = current -> next;
            if (prev)
                prev -> next = temp;
            else
                *begin_list = temp;
            free(current);
            current = temp;
        }
        else
        {
            prev = current;
            current = current ->next;
        }
    }
}