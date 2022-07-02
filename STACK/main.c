#include <stdio.h>
#include <stdlib.h>


typedef struct list
{
    int value;
    struct list* next;
}
list_t;

void insert_push(list_t* my_list, int value)
{
    list_t* new_element = (list_t*)malloc(sizeof(list_t));
    new_element->next = NULL;
    new_element->value = value;

    if (my_list->next == NULL)
    {
        my_list->next = new_element;
    }
    else if (my_list->next != NULL)
    {
        while (my_list->next != NULL)
        {
            my_list = my_list->next;
        }
        my_list->next = new_element;
    }
}

void delete_pop(list_t* my_list)
{
    if (my_list->next == NULL)
    {
        printf("!\n");
    }
    else
    {
        while (my_list->next->next != NULL)
        {
            my_list = my_list->next;
        }
        printf("%d\n", my_list->next->value);
        free(my_list->next);
        my_list->next = NULL;
    }
}

void print_by_index(list_t* my_list, int index)
{
    int i = 0;
    if (my_list->next == NULL) printf("?\n");
    else
    {
        my_list = my_list->next;
        for (i = 0; i < index; i++)
        {
            if (my_list->next == NULL)
            {
                printf("?\n");
                return;
            }
            my_list = my_list->next;
        }
        printf("%d\n", my_list->value);
    }
}

void free_memory(list_t* my_list)
{
    list_t* help = my_list;

    while (help->next != NULL)
    {
        list_t* temporary = help->next;
        free(help);
        help = temporary;
    }
    free(help);
}


int main()
{
    char option;
    int key, index;

    list_t* my_list = (list_t*)malloc(sizeof(list_t));
    my_list->next = NULL;

    scanf("%c", &option);
    while (option != 'q')
    {
        switch (option)
        {
        case 'i':
            scanf("%d", &key);
            insert_push(my_list, key);
            break;
        case 'd':
            delete_pop(my_list);
            break;
        case 'g':
            scanf("%d", &index);
            print_by_index(my_list, index);
            break;
        }
        scanf("%c", &option);
    }

    free_memory(my_list);


    return 0;
}
