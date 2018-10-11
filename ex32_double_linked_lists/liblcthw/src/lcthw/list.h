#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typdedef struct ListNode{
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typdedef struct List{
  int count;
  ListNode *first;
  ListNode *last;
} List;

List *List_create();
void List_destroy(List * list);
void List_clear(List * list);
