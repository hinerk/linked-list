#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked-list.h"


bool _list_is_empty(linked_list_t * list) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called _list_is_empty(%p)\n", list);
    #endif
    return list == NULL || list->next == NULL && list->data == NULL;
}


bool _list_is_of_size_1(linked_list_t * list) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called _list_is_of_size_1(%p)\n", list);
    #endif
    return list->next == NULL && list->data != NULL;
}


linked_list_t * linked_list_new() {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called linked_list_new()\n");
    #endif
    linked_list_t * new_list;

    new_list = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_list->data = NULL;
    new_list->next = NULL;
    return new_list;
}


void linked_list_free(linked_list_t * list) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called linked_list_free(%p)\n", list);
    #endif
    if (list == NULL) return;
    if (list->next !=NULL) linked_list_free(list->next);
    free(list);
}


void linked_list_append(linked_list_t * list, void * data) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called linked_list_append(list=%p, data=%p)\n", list, data);
    #endif
    if (list->next != NULL) return linked_list_append(list->next, data);

    if (list->data == NULL) list->data = data;
    else {
        list->next = linked_list_new();
        list->next->data = data;
    }
}


int linked_list_len(linked_list_t * list) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called linked_list_len(%p)\n", list);
    #endif
    if (_list_is_empty(list)) return 0;
    if (_list_is_of_size_1) return 1;
    return 1 + linked_list_len(list->next);
}


void * linked_list_index(linked_list_t * list, int index) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called linked_list_index(list=%p, index=%d)\n", list, index);
    #endif
    if (index == 0) return list->data;
    if (index > 0 && list->next == NULL) {
        fprintf(stderr, "ERROR! index exceeds list length!\n");
        return NULL;
    }
    return linked_list_index(list->next, index-1);
}


linked_list_t * _linked_list_map(linked_list_t * list, void * (*func)(void *)) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called _linked_list_map(list=%p, func=%p)\n", list, func);
    #endif
    if (_list_is_empty(list)) return NULL;
    linked_list_t * new = linked_list_new();
    new->data = func(list->data);
    new->next = _linked_list_map(list->next, func);
    return new;
}


void _linked_list_discard_map(linked_list_t * list, void * (*func)(void *)) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called _linked_list_discard_map(list=%p, func=%p)\n", list, func);
    #endif
    if (_list_is_empty(list)) return;
    func(list->data);
    _linked_list_discard_map(list->next, func);
}


linked_list_t * _linked_list_filter(linked_list_t * list, bool (*func)(void *)) {
    #ifdef LINKED_LIST_DEBUG
    fprintf(stderr, "called _linked_list_filter(list=%p, func=%p)\n", list, func);
    #endif
    if (_list_is_empty(list)) return NULL;
    if (!func(list->data)) return _linked_list_filter(list->next, func);

    linked_list_t * new = linked_list_new();
    new->data = list->data;
    new->next = _linked_list_filter(list->next, func);
    return new;
}
