#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_t linked_list_t;

typedef struct linked_list_t {
    void * data;
    linked_list_t * next;
} linked_list_t;

linked_list_t * linked_list_new();
void linked_list_free(linked_list_t * list);
void linked_list_append(linked_list_t * list, void * data);
int linked_list_len(linked_list_t * list);
void * linked_list_index(linked_list_t * list, int index);

linked_list_t * _linked_list_map(linked_list_t * list, void * (* func)(void *));

/**
 * @brief applies a function to each element of a list
 *
 * @param list
 * @param func
 * @return new linked_list containing the results of the operation
 *
 */
#define linked_list_map(list, func) ({\
    _Pragma("GCC diagnostic ignored \"-Wincompatible-pointer-types\"") \
    linked_list_t * ___lst = _linked_list_map(list, func);\
    _Pragma("GCC diagnostic pop") \
    ___lst; \
})


void _linked_list_discard_map(linked_list_t * list, void * (* func)(void *));

/**
 * @brief applies a function to each element of a list and discards the results
 *
 */
#define linked_list_discard_map(list, func) ({\
    _Pragma("GCC diagnostic ignored \"-Wincompatible-pointer-types\"") \
    _linked_list_discard_map(list, func);\
    _Pragma("GCC diagnostic pop") \
})


linked_list_t * _linked_list_filter(linked_list_t * list, bool (*func)(void *));

/**
 * @brief filters a list based of the result of function
 *
 */
#define linked_list_filter(list, func) ({\
    _Pragma("GCC diagnostic ignored \"-Wincompatible-pointer-types\"") \
    linked_list_t * ___lst = _linked_list_filter(list, func);\
    _Pragma("GCC diagnostic pop") \
    ___lst; \
})

#endif
