# include <stdio.h>
# include "ft_list.h"


int get_len(t_list *node)
{
    t_list *curr;
    int len;
    len = 0;
    curr = node;
    while(curr)
    {
        curr = curr->next;
        len++;
    }
    return len;
}
void ft_list_reverse_fun(t_list *begin_list)
{
    int i;
    int l;
    int r;
    void *tmp;
    int len = get_len(begin_list);
    t_list *curr;
    t_list *adrr[len];
    
    curr = begin_list;
    i = 0;
    while(i < len)
    {
        adrr[i++] = curr;
        curr = curr->next;
    }
    curr = begin_list;
    
    r = len - 1;
    l = 0;
    while(l < r)
    {
        tmp = adrr[l]->data;
        adrr[l]->data = adrr[r]->data;
        adrr[r]->data = tmp;

        l++;
        r--;
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
    t_list *node5 = malloc(sizeof(t_list));
    t_list *node6 = malloc(sizeof(t_list));

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    node1->data = &a;
    node1->next = node2;

    node2->data = &b;
    node2->next = node3;

    node3->data = &c;
    node3->next = node4;

    node4->data = &d;
    node4->next = node5;

    node5->data = &e;
    node5->next = node6;

    node6->data = &f;
    node6->next = NULL;

    head = node1;

    printf("before\n");
    print_list(head);
    ft_list_reverse_fun(head);
    printf("\nafter\n");
    print_list(head);
    printf("\n");
}