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
void _linked_list_apply(linked_list_t * list, void * (* func)(void *));
#define linked_list_apply(list, func) {\
    _Pragma("GCC diagnostic ignored \"-Wincompatible-pointer-types\"") \
    _linked_list_apply(list, func);\
    _Pragma("GCC diagnostic pop") \
}
