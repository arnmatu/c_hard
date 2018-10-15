#include "lcthw/list.h"
#include "lcthw/dbg.h"
//creates a list
List *List_create()
{
  return calloc(1,sizeof(List));
}
//destroys list and all elements
void List_destroy(List * list)
{
  LIST_FOREACH(list,first,next,cur){
    if (cur->prev){
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);
}
//removes values of each node
void List_clear(List * list)
{
  LIST_FOREACH(list,first,next,cur){
    free(cur->value);
  }
}
//clears and destroys list
void List_clear_destroy(List *list)
{
  List_clear(list);
  List_destroy(list);
}
//adds node to the end of a list
void List_push(List *list, void *value)
{
  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if(list->last == NULL){
    list->first = node;
    list->last = node;
  } else {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }

  list->count++;
error:
  return;
}

//takes last element adn returns it
void *List_pop(List * list)
{
  ListNode *node = list->last;
  return node != NULL ? List_remove(list, node) : NULL;
}
//adds node to the front of list
void List_unshift(List * list, void *value)
{
  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if (list->first == NULL){
    list->first = node;
    list->last = node;
  } else {
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }

  list->count++;

error:
  return;
}
//removes first element and returns it
void *List_shift(List * list)
{
  ListNode *node = list->first;
  return node != NULL ? List_remove(list,node) : NULL;
}
//removes specified node of the list
void *List_remove(List * list, ListNode * node)
{
  void *result = NULL;

  check(list->first && list->last, "List is empty.");
  check(node, "node can't be null");

  if(node == list->first && node == list->last){
    list->first = NULL;
    list->last = NULL;
  } else if (node == list->first){
    list->first = node -> next;

    check(list->first != NULL, "Invalid list, firs node = null");
    list->first->prev = NULL;
  } else if (node == list->last){
    list->last = node->prev;

    check(list->last != NULL, "Invalid list next is null.")
    list->last->next = NULL;
  } else{
    ListNode *after = node->next;
    ListNode *before = node->prev;
    after->prev = before;
    before->next = after;
  }

  list->count--;
  result = node->value;
  free(node);

error:
  return result;
}


void List_printer (List *list, char *msg)
{
  printf("---%s----- \n",msg);
  LIST_FOREACH(list,first,next,cur){
    printf("-- %s ", cur->value);
  }
  printf("\n");
}
