#ifndef LIST_REMOVE_H
#define LIST_REMOVE_H

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

#endif