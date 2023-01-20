#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: integer to be stored
 * @prev: pointer to previous element
 * @next: pointer to next element
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void list_split_merge(int *array, int start, int end, int *copy);
void top_down_merge(int *array, int beg, int mid, int end, int *copy);
void print_range(int *array, int start, int stop);
void swap(int *a, int *b);
void heapify(int *array, size_t count, int i);
void sift_down(int *array, long start, long end, size_t count);
int len_list(listint_t *h);

#endif /* SORT_H */
