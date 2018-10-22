#include "lcthw/list.h"
#include "lcthw/list_algos.h"
#include "lcthw/dbg.h"


int List_bubble_sort(List *list, List_compare cmp)
{
  ListNode *ni = NULL;
  int sorted;
  if (list->count == 1 ) return 0;
  do {
    sorted = 1;
    for(ni = list->first; ni !=NULL; ni = ni->next){
      if(ni->next){
        if(cmp(ni->value, ni->next->value) > 0){
          Node_swap(ni,ni->next);
          sorted = 0;
        }
      }
    }
  } while (!sorted);
/*
  for(ni = list->first; ((ni != NULL) && (ni->next)) ; ni = ni->next){
    if (ni->next){
      printf("LISTAS -- cur = %s next = %s \n", ni->value, ni->next->value);
    } else {
      printf("LISTAS -- cur = %s \n", ni->value);
    }
  }
*/
  return 0;
}


List *List_merge_sort(List *list, List_compare cmp)
{

  if (list->count ==1 ) {
    //List_printer(list,"Single LIST");
     return list; }

  List *Llist = List_create();
  List *Rlist = List_create();


  int rcount = list->count / 2;
  int lcount = list->count - rcount;
  int idx = 1;
  LIST_FOREACH(list,first,next,cur){
    if( idx <= lcount) {
      List_push(Llist, cur->value);
    } else {
      List_push(Rlist, cur->value);
    }
    idx++;
  }
//  List_printer(Llist,"LEFT LIST");
//  List_printer(Rlist,"RIGTH LIST");



  List *sort_left = List_merge_sort(Llist, cmp);
  List *sort_rigt = List_merge_sort(Rlist, cmp);

  return List_merge(Llist,Rlist, cmp);
}

List *List_merge(List *list_l, List *list_r, List_compare cmp)
{
  List *result = List_create();
  void *val = NULL;

  List_printer(list_l, "LEFT PASSED INTO RESULT PRINTER");
  List_printer(list_r, "RIGHT PASSED INTO RESULT PRINTER");
  while (List_count(list_l)>0 || List_count(list_r)>0)
  {
    if(List_count(list_l)>0 && List_count(list_r)>0){
      if (cmp(List_first(list_l),List_first(list_r))<=0){
        val = List_shift(list_l);
      } else {
        val = List_shift(list_r);
      }
      List_push(result,val);
    } else if (List_count(list_l) >0){
        val = List_shift(list_l);
        List_push(result, val);
    } else if(List_count(list_r) >0){
        val = List_shift(list_r);
        List_push(result, val);
    }

  }
  List_printer(result, "RESULT PRINTER");
  return result;
}



inline void Node_swap(ListNode *n1, ListNode*n2)
{
  void *temp = n1->value;
  n1->value = n2->value;
  n2->value = temp;
}
