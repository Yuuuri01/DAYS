# include <stdio.h>
# include "ft_list.h"


t_list *ft_create_ele(void *data)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if(!new)
        return NULL;

    new->data = data;
    new->next = NULL;
    return new;
}
int cmp(int *a, int *b)
{
    return (*a - *b);
}
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list *new;
    t_list *next;
    t_list *curr;
    t_list *prev;

    if(!begin_list || !cmp)
        return;
    if(!*begin_list)
    {
        new = ft_create_ele(data);
        new->next = *begin_list;
        *begin_list = new;
        return;
    }
    curr = *begin_list;
    if(cmp(curr->data, data) > 0)
    {
        new = ft_create_ele(data);
        new->next = curr;
        *begin_list = new;
        return;
    }
    prev = NULL;
    while(curr)
    {
        next = curr->next;
        if(cmp(curr->data, data) > 0)      
        {
            new = ft_create_ele(data);
            prev->next = new;
            new->next = curr;
            return;
        }
        else if(!curr->next && cmp(data, curr->data) > 0)
        {
            new = ft_create_ele(data);
            curr->next = new;
            return;
        }
        else
            prev = curr;
        curr = next;
    }
}
void print_list(t_list *node)
{
    if(node == NULL)
        return;
    printf("%d ", *(int *)node->data);
    print_list(node->next);
}
int main()
{
    t_list *head;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 5;

    int data = 0;
    node1->data = &a;
    node1->next = node2;

    node2->data = &b;
    node2->next = node3;

    node3->data = &c;
    node3->next = node4;

    node4->data = &d;
    node4->next = NULL;

    head = node1;
    printf("before\n");
    print_list(head);
    printf("----------------------\n");
    ft_sorted_list_insert(&head, &data, cmp);
    printf("after\n");
    print_list(head);
    printf("\n");

}