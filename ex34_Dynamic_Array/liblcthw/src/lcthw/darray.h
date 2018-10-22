#ifndef _Darray_h
#define _Darray_h
#include <stdlib.h>
#include <assert.h>
#include <lcthw/dbg.h>

typedef struct DArray {
  int end;
  int max;
  size_t element_size;
  size_t expand_rate;
  void **contents;
} DArray;

DArray *DArray_create (size_t element_size, size_t initial_max);

void DArray_destroy(DArray * array);

void DArray_clear(DArray * array);

int DArray_expand(DArray * array);

int DArray_contract(DArray * array);
// adds to the end of a list
int DArray_push(DArray *array, void *el);
//takes last element and returns
void *DArray_pop(DArray * array);

void DArray_clear_destroy(DArray * array);

#define DArray_last(A) ((A)->contents[(A)->end -1])
#define DArray_first(A) ((A)->contents[0]);
