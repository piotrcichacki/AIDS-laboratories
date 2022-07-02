#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binary_search(int elements_in_seq, int* sequence, int element_to_find)
{
    int indeks = -1, left = 0, right = elements_in_seq - 1, middle;
    bool increasing;
    if (*(sequence + 1) - *sequence > 0) increasing = true;
    else increasing = false;

    while (left < right)
    {
        middle = (left + right) / 2;
        if (increasing)
        {
            if (*(sequence + middle) < element_to_find)
            {
                left = middle + 1;
            }
            else right = middle;
        }
        else if (!increasing)
        {
            if (*(sequence + middle) > element_to_find)
            {
                left = middle + 1;
            }
            else right = middle;
        }
    }
    if (*(sequence + left) == element_to_find) indeks = left;

    return indeks;
}

int main()
{
    int tests = 0, i = 0, elements_in_seq = 0, j = 0, elements_to_find = 0;

    scanf_s("%d", &tests);

    for (i = 0; i < tests; i++)
    {
        scanf_s("%d", &elements_in_seq);
        int* sequence = (int*)malloc(elements_in_seq * sizeof(int));
        for (j = 0; j < elements_in_seq; j++)
        {
            scanf_s("%d", (sequence + j));
        }
        scanf_s("%d", &elements_to_find);
        int* to_find = (int*)malloc(elements_to_find * sizeof(int));
        for (j = 0; j < elements_to_find; j++)
        {
            scanf_s("%d", (to_find + j));
            printf("%d\n", binary_search(elements_in_seq, sequence, *(to_find + j)));
        }
        free(sequence);
        free(to_find);
    }
    return 0;
}
