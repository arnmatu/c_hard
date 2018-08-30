/* WARNING:  This code is fresh and potentially isn't correct yet. */


#include <stdio.h>
#include <glob.h>
#include <string.h>
#include <stdlib.h>

#include "dbg.h"

//globals
#define AND_CONDITION 0
#define OR_CONDITION 1

char *words[] = {};
int compare_oper;

int scan_file(const char *filename, int count, char *words){
  FILE *file = NULL;
  file = fopen(filename, "r");
  check(file, "Could not open file %s \n", filename);



  return 0;
error:
  return -1;
}


int init(int argc, char *argv[], char *words[]){
  //check if number of arguments are ok
  check((argc > 1), "Incorrect number of arguments.")
  //allocate array of pointers
  *words = (char *)malloc(sizeof(char *) * argc);
  //accept initial OR_CONDITION
  compare_oper = OR_CONDITION;
  for (int i = 1; i < argc; i++){
    words[i-1] = argv[i];
    printf("is ciklo %d:%s \n",i, words[i-1]);
    if (strcmp(words[i-1],"-o") == 0) {compare_oper = AND_CONDITION; printf("AND_CONDITION applied\n" );}
  }
  return 0;
error:
  return -1;
}

int main (int argc, char *argv[]){
  init(argc,argv,words);









  return 0;
error:
  return 1;
}
