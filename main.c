#include <stdio.h>
#include "linked-list.h"
#include <string.h>
#include <stdlib.h>


char * to_upper(char * str) {
    char * res;
    char *res_ptr;

    res = malloc(strlen(str) + 1);

    res_ptr = res;

    while (*str != '\0') {
        *res_ptr = *str - (*str >= 'a' && *str <= 'z' ? ('a' - 'A') : 0);
        str++;
        res_ptr++;
    }
    *res_ptr = '\0';
    return res;
}



int main() {
    char * str = "aabc";
    str = to_upper(str);
    printf("%s\n", str);

    linked_list_t * list = linked_list_new();

    printf("empty list size: %d\n", linked_list_len(list));

    printf("adding \"a\"\n");
    linked_list_append(list, "a");
    printf("list size: %d\n", linked_list_len(list));

    printf("adding \"b\"\n");
    linked_list_append(list, "b");
    printf("list size: %d\n", linked_list_len(list));

    printf("adding \"c\"\n");
    linked_list_append(list, "c");
    printf("list size: %d\n", linked_list_len(list));

    char * content;
    content = (char *) linked_list_index(list, 0);
    printf("content from index 0: \"%s\"\n", content);

    content = (char *) linked_list_index(list, 1);
    printf("content from index 1: \"%s\"\n", content);

    content = (char *) linked_list_index(list, 2);
    printf("content from index 2: \"%s\"\n", content);

    content = (char *) linked_list_index(list, 3);
    printf("content from index 3: \"%s\"\n", content);

    list = linked_list_map(list, to_upper);

    content = (char *) linked_list_index(list, 0);
    printf("content from index 0: \"%s\"\n", content);

    content = (char *) linked_list_index(list, 1);
    printf("content from index 1: \"%s\"\n", content);

    content = (char *) linked_list_index(list, 2);
    printf("content from index 2: \"%s\"\n", content);

    content = (char *) linked_list_index(list, 3);
    printf("content from index 3: \"%s\"\n", content);
}