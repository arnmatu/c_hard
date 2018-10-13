#include "minunit.h"
#include <lcthw/list_algos.h>
#include <lcthw/list.h>
#include <assert.h>
#include <string.h>

char *values[] = { "XXXX", "1234", "abcd", "xjvef", "NDSS"};

#define NUM_VALUES 5

List *create_words()
{
  int i = 0;
  List *words = List_create();

  for (i = 0; i < NUM_VALUES; i++){
    List_push(words, values[i]);
  }

  return words;
}
