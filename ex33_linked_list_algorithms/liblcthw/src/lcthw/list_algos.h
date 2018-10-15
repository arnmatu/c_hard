#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h
#include <lcthw/list.h>
#include <stdlib.h>
#include <string.h>
/*
Syntax

The syntax for the strcmp function in the C Language is:

int strcmp(const char *s1, const char *s2);
Parameters or Arguments

s1
An array to compare.
s2
An array to compare.
Returns

The strcmp function returns an integer. The return values are as follows:

Return Value	Explanation
0	s1 and s2 are equal
Negative integer	The stopping character in s1 was less than the stopping character in s2
Positive integer	The stopping character in s1 was greater than the stopping character in s2*/

typedef int (*List_compare) (const void *node1, const void *node2);
int List_bubble_sort(List *list, List_compare cmp);
List *List_merge_sort(List *list, List_compare cmp);
List *List_merge(List *list_l, List *list_r, List_compare cmp);
void Node_swap(ListNode *n1, ListNode*n2);

#endif
