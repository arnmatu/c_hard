/* WARNING:  This code is fresh and potentially isn't correct yet. */


#include <stdio.h>
#include <glob.h>
#include <string.h>

#include "dbg.h"

#define MAX_ARG 5
#define AND_CONDITION 0
#define OR_CONDITION 1

int main (int argc, char *argv[]){

  check((argc > 1 || argc >5), "Incorrect number of arguments.")
  int i;
  char *patern[MAX_ARG];
  int cond = AND_CONDITION;

  for (i = 1; i < argc; i++){
    if (argv[i][0] == '-' && argv[i][1] == 'o') cond = OR_CONDITION;
    else { patern[i-1] = argv[i];}
  }





  return 0;
error:
  return 1;
}
