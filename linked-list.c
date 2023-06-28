#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked-list.h"


bool _list_is_empty(linked_list_t * list) {
    return list == NULL || list->next == NULL && list->data == NULL;
}


bool _list_is_of_size_1(linked_list_t * list) {
    return list->next == NULL && list->data != NULL;
}


linked_list_t * linked_list_new() {
    linked_list_t * new_list;

    new_list = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_list->data = NULL;
    new_list->next = NULL;
    return new_list;
}


void linked_list_free(linked_list_t * list) {
    if (list == NULL) return;
    if (list->next !=NULL) linked_list_free(list->next);
    free(list);
}


void linked_list_append(linked_list_t * list, void * data) {
    if (list->next != NULL) return linked_list_append(list->next, data);

    if (list->data == NULL) list->data = data;
    else {
        list->next = linked_list_new();
        list->next->data = data;
    }
}


int linked_list_len(linked_list_t * list) {
    if (_list_is_empty(list)) return 0;
    if (_list_is_of_size_1) return 1;
    return 1 + linked_list_len(list->next);
}


void * linked_list_index(linked_list_t * list, int index) {
    if (index == 0) return list->data;
    if (index > 0 && list->next == NULL) {
        fprintf(stderr, "ERROR! index exceeds list length!\n");
        return NULL;
    }
    return linked_list_index(list->next, index-1);
}


void _linked_list_apply(linked_list_t * list, void * (*func)(void *)) {
    if (_list_is_empty(list)) return;
    list->data = func(list->data);
    if (list->next != NULL) _linked_list_apply(list->next, func);
}
